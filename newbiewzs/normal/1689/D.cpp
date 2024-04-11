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
//#define int long long
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
const int N=1005;
int T,n,m,ax,ay,b[N],v[10];
char a[N][N];
set<int>s[N];
bool check(int u){
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			s[i].insert(k);
		}
	}
	
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	for(int ii=1;ii<=T;ii++){
		n=read();m=read();
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
		}
		/*int l=0,r=2000;
		#define mid ((l+r)>>1)
		while(l<=r){
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		cout<<ax<<" "<<ay<<'\n';
		for(int i=1;i<=n;i++)b[i]=0;*/
		v[0]=1e9;
		v[1]=v[2]=v[3]=-1e9;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=m;k++){
				if(a[i][k]=='B'){
					v[0]=min(v[0],i+k);
					v[1]=max(v[1],k-i);
					v[2]=max(v[2],i-k);
					v[3]=max(v[3],i+k);
				}
			}
		}
		int maxx=1e9;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=m;k++){
				int kel=max(max(i+k-v[0],i-k+v[1]),max(-i+k+v[2],v[3]-i-k));
				if(kel<maxx){
					ax=i;ay=k;
					maxx=kel;
				}
			}
		}
		cout<<ax<<" "<<ay<<'\n';
	}
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}