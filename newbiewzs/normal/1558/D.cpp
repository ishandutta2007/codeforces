#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
//#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=2e5+55;
const int mod=998244353;
int T,n,m,x,y,cd[N],cy[N],fac[N*2],ifac[N*2],st[N],top;
int pd[N],ans;
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
int summ[N*4];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int C(int n,int m){
	if(n<m)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void add(int u,int l,int r,int x,int k){
	if(l==r){
		summ[u]+=k;return ;
	}
	if(x<=mid)add(ls,l,mid,x,k);
	else add(rs,mid+1,r,x,k);
	summ[u]=summ[ls]+summ[rs];
}
int ask(int u,int l,int r,int x){
	if(l==r)return l;
	if(summ[ls]>=x)return ask(ls,l,mid,x);
	else return ask(rs,mid+1,r,x-summ[ls]);
}
void build(int u,int l,int r){
	if(l==r){
		summ[u]=1;return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	summ[u]=summ[ls]+summ[rs];
}
void clear(int u,int l,int r){
	summ[u]=0;
	if(l==r){
		pd[l]=0;return;
	}
	clear(ls,l,mid);
	clear(rs,mid+1,r);
}
void solve(){
	ans=0;
	map<int,int>ma;
	for(int i=m;i>=1;i--){
		x=ask(1,1,N-55,cd[i]);
		y=ask(1,1,N-55,cd[i]+1);
		add(1,1,N-55,x,-1);
		st[++top]=x;
		if(!ma[y])ans++;
		ma[y]=1;
	}
	for(int i=1;i<=top;i++)add(1,1,N-55,st[i],1);top=0;
	cout<<C(2*n-1-ans,n)<<'\n';
}
int main(){
	fac[0]=ifac[0]=1;
	for(int i=1;i<=N*2-5;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[N*2-5]=ksm(fac[N*2-5],mod-2);
	for(int i=N*2-6;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	build(1,1,N-55);
	cin>>T;
	while(T--){
		n=read();m=read();
		for(int i=1;i<=m;i++)x=read(),y=read(),cd[i]=y;	
		solve();
	}
	return 0;
}
/*
1
5 3
3 1
4 1
5 3
*/