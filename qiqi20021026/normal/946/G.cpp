#include<bits/stdc++.h>

using namespace std;

#define N 300000
#define M 1000300000
#define INF 0x3f3f3f3f

int n,cnt,rt,a[N],seg[N*30][3],ls[N*30],rs[N*30],f[N][2];

void mdf(int op,int &x,int l,int r,int k,int t){
	if (!x){x=++cnt; seg[x][0]=seg[x][1]=seg[x][2]=INF;}
	if (l==r){seg[x][op]=t; return;}
	int mid=(l+r)>>1;
	if (k<=mid) mdf(op,ls[x],l,mid,k,t);
	else mdf(op,rs[x],mid+1,r,k,t);
	seg[x][op]=min(seg[ls[x]][op],seg[rs[x]][op]);
}

int qry(int op,int x,int l,int r,int L,int R){
	if (!x||L>R) return INF;
	if (l>=L&&r<=R) return seg[x][op];
	int mid=(l+r)>>1,tmp=INF;
	if (L<=mid) tmp=min(tmp,qry(op,ls[x],l,mid,L,R));
	if (R>mid) tmp=min(tmp,qry(op,rs[x],mid+1,r,L,R));
	return tmp;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){scanf("%d",&a[i]); a[i]+=n;}
	a[++n]=M;
	seg[0][0]=seg[0][1]=seg[0][2]=INF;
	memset(f,0x3f,sizeof f);
	for (int i=1;i<=n;++i){
		f[i][0]=i-1; if (i>=2) f[i][1]=i-2;
		f[i][0]=min(f[i][0],qry(0,rt,1,M,1,a[i]-i)+i-1);
		f[i][1]=min(f[i][1],qry(1,rt,1,M,1,a[i]-i)+i-1);
		f[i][1]=min(f[i][1],qry(2,rt,1,M,1,a[i]-i+1)+i-2);
		f[i][0]=max(f[i][0],0);
		f[i][1]=max(f[i][1],0);
		mdf(0,rt,1,M,a[i]-i,f[i][0]-i);
		mdf(1,rt,1,M,a[i]-i,f[i][1]-i);
		mdf(2,rt,1,M,a[i-1]-(i-1),f[i-1][0]-(i-1));
	}
	printf("%d\n",f[n][1]);
	
	return 0;
}