#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define fl fflush(stdout)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
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
const int mod=998244353;
const int N=2e5+5;
const int M=3050;
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int inv(int x){
	return ksm(x,mod-2);
}
int add(int x,int y){
	return (x+y>=mod?x+y-mod:x+y);
}
int n,m,a[N],w[N],A,B;
int f[M][M],g[M][M];
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		if(a[i]==1)A=add(A,w[i]);
		else B=add(B,w[i]); 
	}
	for(int i=0;i<=m;i++)g[i][m-i]=f[i][m-i]=1;
	for(int i=m-1;i>=0;i--){
		for(int k=0;k<=i;k++){
			int j=i-k;
			if(B-j<0)continue;
			const int tmp=inv(A+k+B-j);
			f[k][j]=add(1ll*(A+k+1)*tmp%mod*f[k+1][j]%mod,1ll*(B-j)*tmp%mod*f[k][j+1]%mod);
			g[k][j]=add(1ll*(A+k)*tmp%mod*g[k+1][j]%mod,1ll*(B-j-1)*tmp%mod*g[k][j+1]%mod);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cout<<1ll*w[i]*f[0][0]%mod<<'\n';
		}
		else{
			cout<<1ll*w[i]*g[0][0]%mod<<'\n';
		}
	}
	return 0;
}