#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
// #pragma GCC optimize(3)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
	}
	char ssss[19999999],tttt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ssss[++ssl]='-',x=(-x);
		if(!x) ssss[++ssl]='0';for(ttl=0;x;x/=10) tttt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ssss[++ssl]=tttt[ttl];return ssss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ssss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
namespace CFConTest{
	const int mod=998244353;
	inline int add(const int &x,const int &y){
		return (x+y>=mod?x+y-mod:x+y);
	}
	inline int del(const int &x,const int &y){
		return (x-y<0?x-y+mod:x-y);
	}
	int ksm(int x,int k){
		int base=1;
		while(k){
			if(k&1)base=1ll*base*x%mod;
			k>>=1;
			x=1ll*x*x%mod;
		}
		return base;
	}
};
using namespace CFConTest;
const int N=2e5+5;
const int M=2e5;
int n,m,a[N],b[N],tong[N],p[N],inv[N];
int summ[N*4],val[N*4];
int f[N*4][2];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void build(int u,int l,int r){
	if(l==r){
		summ[u]=0;
		f[u][0]=inv[summ[u]];
		f[u][1]=0;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	summ[u]=summ[ls]+summ[rs];
	f[u][0]=1ll*f[ls][0]*f[rs][0]%mod;
	f[u][1]=add(1ll*f[ls][1]*f[rs][0]%mod,1ll*f[ls][0]*f[rs][1]%mod);
}
void add(int u,int l,int r,int x,int k){
	if(l==r){
		summ[u]+=k;
		if(summ[u]==0)f[u][0]=inv[summ[u]],f[u][1]=0;
		else {
			f[u][0]=inv[summ[u]];
			f[u][1]=inv[summ[u]-1];
		}
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,k);
	if(x>mid)add(rs,mid+1,r,x,k);
	summ[u]=summ[ls]+summ[rs];
	f[u][0]=1ll*f[ls][0]*f[rs][0]%mod;
	f[u][1]=add(1ll*f[ls][1]*f[rs][0]%mod,1ll*f[ls][0]*f[rs][1]%mod);
}
int sa=0,sb=0;
void query(int u,int l,int r,int L,int R){
	if(L>R){
		sa=sb=0;
		return ;
	}
	if(L<=l && R>=r){
		int tb=add(1ll*sa*f[u][1]%mod,1ll*sb*f[u][0]%mod);
		sb=tb;
		sa=1ll*sa*f[u][0]%mod;
		return ;
	}
	if(L<=mid)query(ls,l,mid,L,R);
	if(R>mid)query(rs,mid+1,r,L,R);
}
void ask(int u,int l,int r,int L,int R){
	if(L>R){
		sa=sb=0;
		return ;
	}
	if(L<=l && R>=r){
		sb=1ll*sb*f[u][0]%mod;
		return ;
	}
	if(L<=mid)ask(ls,l,mid,L,R);
	if(R>mid)ask(rs,mid+1,r,L,R);
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	p[0]=1;
	for(int i=1;i<=n;i++)p[i]=1ll*p[i-1]*i%mod;
	for(int i=0;i<=n;i++)inv[i]=ksm(p[i],mod-2);
	build(1,1,M);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<=n;i++){
		add(1,1,M,a[i],1);
		tong[a[i]]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		sa=1;sb=0;
		query(1,1,M,1,b[i]-1);
		ask(1,1,M,b[i],M);
		ans=add(ans,1ll*p[n-i]*sb%mod);
		tong[b[i]]--;
		if(tong[b[i]]<0){
			break;
		}
		add(1,1,M,b[i],-1);
	}
	if(n<m){
		mem0(tong);
		for(int i=1;i<=n;i++)tong[a[i]]++;
		bool flag=1;
		for(int k=1;k<=n;k++){
			tong[b[k]]--;
			if(tong[b[k]]==-1)flag=0;
		}
		if(flag)ans++;
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}