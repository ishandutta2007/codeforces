#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=(1<<12)+5;
const int B=256;
int n,q,a[N];
int pos[N];
int tot,cnt;
int stx[N*B*2],sty[N*B*2],top;
int hb(int x,int y){
	if(!x|!y)return x|y;
	stx[++tot]=x;
	sty[tot]=y;
	return tot;
}
struct node{
	vector<int>id;
	map<int,int>ma[N];
	int cx(int l,int r){
	//	if(l==2 and r==3){
	//		new char;
	//	}
		if(l>id.back())return 0;
		if(r<id.front())return 0;
		int x=lower_bound(id.begin(),id.end(),l)-id.begin();
		int y=upper_bound(id.begin(),id.end(),r)-id.begin()-1;
		if(x>y)return 0;
	//	cout<<"!"<<ma[x][y]<<endl;
		return ma[x][y];
	}
	friend node operator + (node x,node y){
		node z;
		int head=0,tou=0;
		while(head<x.id.size() and tou<y.id.size()){
			if(x.id[head]<y.id[tou]){
				z.id.push_back(x.id[head]);
				head++;
			}
			else{
				z.id.push_back(y.id[tou]);
				tou++;
			}
		}
		while(head<x.id.size()){
			z.id.push_back(x.id[head]);
			head++;
		}
		while(tou<y.id.size()){
			z.id.push_back(y.id[tou]);
			tou++;
		}
		for(int i=0;i<z.id.size();i++){
			for(int k=i+1;k<z.id.size();k++){
		//		cout<<z.id[i]<<" "<<z.id[k]<<endl;
		//		if(z.id[i]==2 and z.id[k]==3){
		//			new char;
		//		}
				z.ma[i][k]=hb(x.cx(z.id[i],z.id[k]),y.cx(z.id[i],z.id[k]));
			}
			z.ma[i][i]=hb(x.cx(z.id[i],z.id[i]),y.cx(z.id[i],z.id[i]));
		}
		return z;
	}
}t[N/B+1];
int ans[N*B*2];
int x,y;
node fh(int u){
	node g;
	g.id.push_back(pos[u]);
	g.ma[0][0]=pos[u];
	return g;
}
#define mid ((l+r)>>1)
node ycl(int l,int r){
	if(l==r)return fh(l);
	return (ycl(l,mid)+ycl(mid+1,r));
}
int main(){
	n=read();q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		pos[a[i]]=i;
	}
	cnt=n/B+1;
	tot=n;
	for(int i=1;i<=cnt;i++){
		if((i-1)*B+1>n){
			cnt--;
			break;
		}
		t[i]=ycl((i-1)*B+1,min(n,i*B));
	}
	for(int i=1;i<=q;i++){
		x=read();y=read();
		for(int k=1;k<=cnt;k++){
			ans[i]=hb(ans[i],t[k].cx(x,y));
		}
	}
	cout<<tot<<endl;
	for(int i=n+1;i<=tot;i++){
		printf("%d %d\n",stx[i],sty[i]);
	}
	for(int i=1;i<=q;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}