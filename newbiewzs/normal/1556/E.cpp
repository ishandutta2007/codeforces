#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<bitset>
#include<ctime>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
const int N=1e5+5;
int n,m,a[N],b[N],c[N],s[N],x,y;
int summ[N*4],minn[N*4],maxx[N*4];
void build(int u,int l,int r){
	if(l==r){
		minn[u]=maxx[u]=s[l];
		summ[u]=c[l];return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	summ[u]=summ[ls]+summ[rs];
	maxx[u]=max(maxx[ls],maxx[rs]);
	minn[u]=min(minn[ls],minn[rs]);
}
int query(int u,int l,int r,int L,int R){
	if(L<=l and R>=r)return summ[u];
	int tmp=0;
	if(L<=mid)tmp=query(ls,l,mid,L,R);
	if(R>mid)tmp=tmp+query(rs,mid+1,r,L,R);
	return tmp;
}
int queryma(int u,int l,int r,int L,int R){
	if(L<=l and R>=r)return maxx[u];
	int tmp=-1e15;
	if(L<=mid)tmp=queryma(ls,l,mid,L,R);
	if(R>mid)tmp=max(tmp,queryma(rs,mid+1,r,L,R));
	return tmp;
}
int querymi(int u,int l,int r,int L,int R){
	if(L<=l and R>=r)return minn[u];
	int tmp=1e15;
	if(L<=mid)tmp=querymi(ls,l,mid,L,R);
	if(R>mid)tmp=min(tmp,querymi(rs,mid+1,r,L,R));
	return tmp;
}
signed main(){
	n=read();m=read();
	memset(maxx,-10,sizeof(maxx));
	memset(minn,10,sizeof(minn));
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)c[i]=a[i]-b[i],s[i]=s[i-1]+c[i];
	build(1,1,n);
	for(int i=1;i<=m;i++){
		x=read();y=read();
		if(query(1,1,n,x,y)){
			puts("-1");continue;
		}
		else{
			int MX=queryma(1,1,n,x,y);
			int MN=querymi(1,1,n,x,y);
			if(MX-s[x-1]>0){
				puts("-1");continue;
			}
			int ans=max(abs(MX-s[x-1]),abs(MN-s[x-1]));
			printf("%lld\n",ans);
		}
	}
	return 0;
}