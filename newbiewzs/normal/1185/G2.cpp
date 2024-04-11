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
#include<cmath>
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
//#define int long long
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
const int N=55;
const int M=2505;
const int mod=1e9+7;
inline int add(const int &x,const int &y){
	return (x+y>=mod?x+y-mod:x+y);
}
int n,T,x[N],y[N],fac[N],ans;
int sa[4];
int f[N][M],g[N][N][M],w[N][N][N][4],W[N][N][N];
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();T=read();
	fac[0]=1;
	for(int i=1;i<=n;i++){
		x[i]=read();y[i]=read();
		sa[y[i]]++;
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	f[0][0]=g[0][0][0]=1;
	for(int i=1;i<=n;i++){
		if(y[i]==1){
			for(int k=sa[1];k>=1;k--){
				for(int j=T;j>=x[i];j--){
					f[k][j]=add(f[k][j],f[k-1][j-x[i]]);
				}
			}
		}
		else{
			for(int k=sa[2];k>=0;k--){
				for(int j=sa[3];j>=0;j--){
					if(k==0 && y[i]==2)continue;
					if(j==0 && y[i]==3)continue;
					for(int h=T;h>=x[i];h--){
						g[k][j][h]=add(g[k][j][h],g[k-(y[i]==2)][j-(y[i]==3)][h-x[i]]);
					}
				}
			}
		}
	}
	w[1][0][0][1]=1;
	w[0][1][0][2]=1;
	w[0][0][1][3]=1;
	for(int i=0;i<=sa[1];i++){
		for(int k=0;k<=sa[2];k++){
			for(int j=0;j<=sa[3];j++){
				for(int h=1;h<=3;h++){
					if(i && h!=1)w[i][k][j][1]=add(w[i][k][j][1],w[i-1][k][j][h]);
					if(k && h!=2)w[i][k][j][2]=add(w[i][k][j][2],w[i][k-1][j][h]);
					if(j && h!=3)w[i][k][j][3]=add(w[i][k][j][3],w[i][k][j-1][h]);
				}
				W[i][k][j]=add(add(w[i][k][j][1],w[i][k][j][2]),w[i][k][j][3]);
			}
		}
	}
	for(int i=0;i<=sa[1];i++){
		for(int k=0;k<=sa[2];k++){
			for(int j=0;j<=sa[3];j++){
				const int tmp=1ll*fac[i]*fac[k]%mod*fac[j]%mod*W[i][k][j]%mod;
				if(!tmp)continue;
				for(int h=0;h<=T;h++){
					if(!f[i][h] || !g[k][j][T-h])continue;
					ans=add(ans,1ll*f[i][h]*g[k][j][T-h]%mod*tmp%mod);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}