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
// #pra gma GCC opti mize(3)
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
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
inline int gcd(const int &x,const int &y){
	if(!x)return y;
	return gcd(y%x,x);
}
const int N=6005;
int n,x[N],y[N],jl[N][N];
ll ans;
//bitset<N>f[N][4],tmp;
int f[4][4][4];
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read();y[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int k=i+1;k<=n;k++){
			jl[i][k]=abs(gcd(x[k]-x[i],y[k]-y[i]));
		}
	}
	for(int i=1;i<=n;i++){
		mem0(f);
		for(int k=i+1;k<=n;k++){
			int G=jl[i][k];
			f[G%4][x[k]%4][y[k]%4]++;
		}
		for(int k=0;k<4;k++){
			for(int j=0;j<4;j++){
				for(int h=0;h<4;h++){
					for(int hh=0;hh<4;hh++){
						for(int g=0;g<4;g++){
							for(int gg=0;gg<4;gg++){
								int tmp=gcd(hh-h,gg-g);
								if(tmp<0)tmp=-tmp;
								if((k+j+tmp)%4==0){
									if(k!=j || h!=hh || g!=gg)ans=ans+f[k][h][g]*f[j][hh][gg];
									else ans=ans+((f[k][h][g]-1)*f[k][h][g]);
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ans/2;
	return 0;
}