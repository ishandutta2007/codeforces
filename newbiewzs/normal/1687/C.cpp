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
/*namespace CFConTest{
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
using namespace CFConTest;*/
const int N=2e5+5;
int T,n,m,l[N],r[N],bj[N],a[N],b[N],c[N],s[N];
vi L[N],R[N];
int sa[N],sb[N];
struct node{
	int id;
	friend bool operator < (node x,node y){
		if(sa[x.id]!=sa[y.id])return sa[x.id]>sa[y.id];
		if(sb[x.id]!=sb[y.id])return sb[x.id]>sb[y.id];
		return x.id<y.id;
	}
};
multiset<node>S;
int pd[N];
multiset<int>wei;
void solve(int u){
	for(auto i:L[u]){
		auto tmp=S.lower_bound({i});
		if(tmp!=S.end() && (*tmp).id==i){
			S.erase(tmp);
			sa[i]=1;
			S.insert({i});
		}
	}
	for(auto i:R[u]){
		auto tmp=S.lower_bound({i});
		if(tmp!=S.end() && (*tmp).id==i){
			S.erase(tmp);
			sb[i]=1;
			S.insert({i});
		}
	}
}
void work(int l,int r){
	while(1){
		auto i=wei.lower_bound(l);
		if(i==wei.end() || (*i)>r)break;
		solve(*i);
		bj[*i]=1;
		wei.erase(i);
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<=n;i++)c[i]=a[i]-b[i];
		for(int i=1;i<=n;i++)s[i]=s[i-1]+c[i];
		for(int i=1;i<=n;i++)wei.insert(i);
		for(int i=1;i<=m;i++){
			l[i]=read();r[i]=read();
			sa[i]=(s[l[i]-1]==0);
			sb[i]=(s[r[i]]==0);
			L[l[i]-1].pb(i);
			R[r[i]].pb(i);
			S.insert({i});
			pd[i]=0;
		}
		while(S.size()){
			auto kel=S.begin();
			node tmp=(*kel);
			if(sa[tmp.id]!=1 || sb[tmp.id]!=1)break;
			pd[tmp.id]=1;work(l[tmp.id],r[tmp.id]);
			auto kkk=S.lower_bound({tmp.id});
			S.erase(kkk);
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(!bj[i] && a[i]!=b[i])flag=1;
		}
		if(flag)puts("No");
		else puts("Yes");
		wei.clear();
		S.clear();
		for(int i=0;i<=n;i++){
			bj[i]=a[i]=b[i]=c[i]=s[i]=0;
		}
		for(int i=0;i<=n;i++){
			L[i].clear();
			R[i].clear();
		}
		for(int i=1;i<=m;i++)sa[i]=sb[i]=l[i]=r[i]=pd[i]=0;
	}
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}