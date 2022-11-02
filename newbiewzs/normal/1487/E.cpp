#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=5e5;
int q[N],w[N],e[N],r[N];
int a,b,c,d;
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
int minn[N*4];
int f[N];
void build(int u,int l,int r){
	if(l==r){
		minn[u]=f[l];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	minn[u]=min(minn[ls],minn[rs]);
}
int query(int u,int l,int r,int L,int R){
	if(L>R)return 5e12;
	if(L<1)return 5e12;
	if(L<=l and R>=r){
		return minn[u];
	}
	int minn=5e12;
	if(L<=mid)minn=query(ls,l,mid,L,R);
	if(R>mid)minn=min(minn,query(rs,mid+1,r,L,R));
	return minn;
}
int m,x,y;
vector<int>v[N];
signed main(){
	a=read();b=read();c=read();d=read();
	for(int i=1;i<=a;i++)q[i]=read();
	for(int i=1;i<=b;i++)w[i]=read();
	for(int i=1;i<=c;i++)e[i]=read();
	for(int i=1;i<=d;i++)r[i]=read();
	for(int i=1;i<=a;i++)f[i]=q[i];
	m=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();
		v[y].push_back(x);
	}
	build(1,1,a);
	for(int i=1;i<=b;i++){
		sort(v[i].begin(),v[i].end());
		int qz=1;int hh=5e12;
		for(int k=0;k<v[i].size();k++){
			hh=min(hh,query(1,1,a,qz,v[i][k]-1));
			qz=v[i][k]+1;
		}
		hh=min(hh,query(1,1,a,qz,a));
		f[i]=w[i]+hh;
		v[i].clear();
	}
	memset(minn,127,sizeof(minn));
	m=read();
	for(int i=b+1;i<N;i++)f[i]=5e12;
	for(int i=1;i<=m;i++){
		x=read();y=read();
		v[y].push_back(x);
	}
	build(1,1,b);
	for(int i=1;i<=c;i++){
		sort(v[i].begin(),v[i].end());
		int qz=1;int hh=5e12;
		for(int k=0;k<v[i].size();k++){
			hh=min(hh,query(1,1,b,qz,v[i][k]-1));
			qz=v[i][k]+1;
		}
		hh=min(hh,query(1,1,b,qz,b));
		f[i]=e[i]+hh;
		v[i].clear();
	}
	memset(minn,127,sizeof(minn));
	m=read();
	for(int i=c+1;i<N;i++)f[i]=5e12;
	for(int i=1;i<=m;i++){
		x=read();y=read();
		v[y].push_back(x);
	}
	build(1,1,c);
	for(int i=1;i<=d;i++){
		sort(v[i].begin(),v[i].end());
		int qz=1;int hh=5e12;
		for(int k=0;k<v[i].size();k++){
			hh=min(hh,query(1,1,c,qz,v[i][k]-1));
			qz=v[i][k]+1;
		}
		hh=min(hh,query(1,1,c,qz,c));
		f[i]=r[i]+hh;
	}
	memset(minn,127,sizeof(minn));
	int minn=2e15;
	for(int i=1;i<=d;i++){
		minn=min(minn,f[i]);
	}
	if(minn>1e10)puts("-1");
	else cout<<minn;
	return 0;
}