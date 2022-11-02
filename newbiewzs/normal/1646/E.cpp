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
const int N=1e6+5;
const int M=1e6;
int vis[N];
int st[N],las[N],top;
int n,m;
int sa[N],sb[N],head;
void init(){
	for(int i=2;i<=M;i++){
		if(!vis[i])st[++top]=i,las[i]=i;
		for(int k=1;k<=top && st[k]*i<=M;k++){
			vis[i*st[k]]=1;las[i*st[k]]=st[k];
			if(i%st[k]==0)break;
		}
	}
}
bool pd[N*20];
int summ[21];
int hh[N];
signed main(){
	#ifdef newbiewzs
		double startt=clock();
		freopen("data.in","r",stdin);
	#else
	#endif
	init();
	n=read();m=read();
	for(int k=1;k<=20;k++){
		for(int j=k;j<=k*m;j+=k){
			if(!pd[j]){
				pd[j]=1;summ[k]++;
			}
		}
	}
	int ans=1;
//	cout<<1<<'\n';
	mem0(vis);
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			ans=ans+m;
			int u=i;
			int tot=1;
			for(int j=i*i;j<=n;j*=i){
				tot++;
				if(!vis[j]){
					vis[j]=1;
					ans=ans+summ[tot];
				}
				
			}
		}
	}
/*	hh[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			ans=ans+m;
			hh[i]=1;
		//	cout<<m<<'\n';
		}
		else {
			int u=i;head=0;
			while(u!=1){
				int tmp=las[u];
				sa[++head]=tmp;sb[head]=0;
				while(u%tmp==0)u/=tmp,sb[head]++;
			}
			bool flag=1;
			for(int k=1;k<=head;k++){
				if(sb[k]&1)flag=0;
			} 
			if(i==72){
				new char;
			}
			int minn=1e9;
			for(int k=1;k<=head;k++)minn=min(minn,sb[k]);
			ans=ans+summ[minn];
		}
	}*/
	cout<<ans;
    #ifdef newbiewzs
		double endd=clock();
		cerr<<'\n';
		cerr<<"Time:"<<endd-startt<<" ms"<<'\n';
	#endif
	return 0;
}