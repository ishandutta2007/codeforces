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
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
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
const int N=105;
int n,x[N],y[N];
int minn[N];
vi v[N];
int f[N][N];
int dis(int x,int y){
	return abs(::x[x]-::x[y])+abs(::y[x]-::y[y]);
}
int vis[N],bj[N];
int st[N],top,flag;
int g[N],head;
void dfs(int u){
	bj[u]=1;
	st[++top]=u;
	for(auto i:v[u]){
		if(!bj[i])dfs(i);
	}
}
int fac[N],ifac[N];
int A(int x,int y){
	return 1ll*fac[x]*ifac[x-y]%mod;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read();y[i]=read();
		minn[i]=1e15;
	}
	fac[0]=ifac[0]=1;
	for(int i=1;i<=100;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[100]=ksm(fac[100],mod-2);
	for(int i=99;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(i==k)continue;
			minn[i]=min(minn[i],dis(i,k));
		}
		for(int k=1;k<=n;k++){
			if(dis(i,k)==minn[i]){
				v[i].pb(k);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			flag=0;top=0;mem0(bj);
			dfs(i);
			int prp=dis(st[1],st[2]);
			for(int k=1;k<=top;k++){
				for(int j=k+1;j<=top;j++){
					if(dis(st[k],st[j])!=prp)flag=1;
				}
			}
			if(flag==1){
				g[++head]=1;
			}
			else{
				for(int k=1;k<=top;k++)vis[st[k]]=1;
				g[++head]=top;
			}
		}
	}
	f[0][0]=1;
	for(int i=1;i<=head;i++){
		for(int k=1;k<=n;k++){
			f[i][k]=f[i-1][k-1];
			if(k-g[i]>=0 && g[i]>1)f[i][k]=add(f[i][k],f[i-1][k-g[i]]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=add(ans,1ll*A(n,i)*f[head][i]%mod);
	}
	cout<<ans;
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}