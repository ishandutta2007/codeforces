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
//#pragma GCC optimize(3)
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
int T,na,nb,nc,a[N],b[N],c[N];
int sa[N],sb[N],sc[N];
int sq(int x){
	return x*x;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		na=read();nb=read();nc=read();int ans=2e18;
		for(int i=1;i<=na;i++)a[i]=read();
		for(int i=1;i<=nb;i++)b[i]=read();
		for(int i=1;i<=nc;i++)c[i]=read();
		sort(a+1,a+na+1);
		sort(b+1,b+nb+1);
		sort(c+1,c+nc+1);
		for(int i=1;i<=3;i++){
			for(int k=1;k<=3;k++){
				for(int j=1;j<=3;j++){
					if(i==k || k==j || i==j)continue;
					int x,y,z;
					if(i==2){
						for(int h=1;h<=na;h++){
							y=a[h];
							if(k==1)x=b[upper_bound(b+1,b+nb+1,y)-b-1];
							if(j==1)x=c[upper_bound(c+1,c+nc+1,y)-c-1];
							if(x!=0){
								if(k==3)z=b[lower_bound(b+1,b+nb+1,y)-b];
								if(j==3)z=c[lower_bound(c+1,c+nc+1,y)-c];
								if(y && x && z){
									ans=min(ans,sq(x-y)+sq(y-z)+sq(z-x));
								}
							}
						}
					}
					if(k==2){
						for(int h=1;h<=nb;h++){
							y=b[h];
							if(i==1)x=a[upper_bound(a+1,a+na+1,y)-a-1];
							if(j==1)x=c[upper_bound(c+1,c+nc+1,y)-c-1];
							if(x!=0){
								if(i==3)z=a[lower_bound(a+1,a+na+1,y)-a];
								if(j==3)z=c[lower_bound(c+1,c+nc+1,y)-c];
								if(y && x && z){
									ans=min(ans,sq(x-y)+sq(y-z)+sq(z-x));
								}
							}
						}
					}
					if(j==2){
						for(int h=1;h<=nc;h++){
							y=c[h];
							if(i==1)x=a[upper_bound(a+1,a+na+1,y)-a-1];
							if(k==1)x=b[upper_bound(b+1,b+nb+1,y)-b-1];
							if(x!=0){
								if(i==3)z=a[lower_bound(a+1,a+na+1,y)-a];
								if(k==3)z=b[lower_bound(b+1,b+nb+1,y)-b];
								if(y && x && z){
									ans=min(ans,sq(x-y)+sq(y-z)+sq(z-x));
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=na;i++)a[i]=0;
		for(int i=1;i<=nb;i++)b[i]=0;
		for(int i=1;i<=nc;i++)c[i]=0;
		cout<<ans<<'\n';
	}
	return 0;
}