#include<bits/stdc++.h>
using namespace std;
const int M=35009;
int n,k;
int las[M],b[M];
int mi[M<<2][109],vis[M<<2][109];
void pd(int num,int d){
	mi[num<<1][d]+=vis[num][d];
	mi[num<<1|1][d]+=vis[num][d];
	vis[num<<1][d]+=vis[num][d];
	vis[num<<1|1][d]+=vis[num][d];
	vis[num][d]=0;
}
void pu(int num,int d){
	mi[num][d]=min(mi[num<<1][d],mi[num<<1|1][d]);
}
void update(int num,int l,int r,int x,int y,int v,int d){
	if(x>y)return;
	if(x<=l&&r<=y){
		vis[num][d]+=v;
		mi[num][d]+=v;
		return;
	}
	pd(num,d);
	int mid=l+r>>1;
	if(x<=mid)update(num<<1,l,mid,x,y,v,d);
	if(y>mid)update(num<<1|1,mid+1,r,x,y,v,d);
	pu(num,d);
}
void change(int num,int l,int r,int x,int v,int d){
	if(l==r){mi[num][d]=v;return;}
	pd(num,d);
	int mid=l+r>>1;
	if(x<=mid)change(num<<1,l,mid,x,v,d);
	else change(num<<1|1,mid+1,r,x,v,d);
	pu(num,d);
}
int query(int num,int l,int r,int x,int y,int d){
	if(x>y)return 0;
	if(x<=l&&r<=y)return mi[num][d];
	pd(num,d);
	int mid=l+r>>1,ans=1e9;
	if(x<=mid)ans=min(ans,query(num<<1,l,mid,x,y,d));
	if(y>mid)ans=min(ans,query(num<<1|1,mid+1,r,x,y,d));
	return ans;
}
void build(int num,int l,int r){
	if(l==r){
		for(int j=1;j<=k;++j)mi[num][j]=1e9;
		return;
	}
	int mid=l+r>>1;
	build(num<<1,l,mid);
	build(num<<1|1,mid+1,r);
	for(int i=1;i<=k;++i)pu(num,i);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		las[i]=b[x];
		b[x]=i;
	}
	build(1,1,n);
	for(int i=1;i<=n;++i){
		for(int j=k;j>=1;--j){
			if(j>1||i==1){
				int x=query(1,1,n,1,i-1,j-1);
				change(1,1,n,i,x,j);
			}
			update(1,1,n,1,las[i],i-las[i],j);
		}
	}
	printf("%d\n",query(1,1,n,1,n,k));
	return 0;
}