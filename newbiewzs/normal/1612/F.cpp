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
const int N=2e5+5;
int n,m,q,x,y,maxx=1,rev=0,tmp=1;
int f[N*40];
map<pii,int>ma;
int F(int x,int y){
	return (x*(maxx+1)+y);
}
inline int Max(const int &x,const int &y){
	return (x>y?x:y);
}
namespace HM{
	const int mod=1e5+3;
	const int h=233;
	vector<pii>v[mod+2];
	inline int F(const int &x,const int &y){
		return (1ll*x*h+y)%mod;
	}
	inline void add(const int &x,const int &y){
		v[F(x,y)].pb(mp(x,y));
	}
	inline int query(const int &x,const int &y){
		int tmp=F(x,y);
		for(auto i:v[tmp]){
			if(i.fi==x && i.se==y)return 1;
		}
		return 0;
	}
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();q=read();
	if(n>m)swap(n,m),rev=1;
	while(tmp<=n){
		maxx++;
		tmp*=2;
	}
	maxx*=2;maxx+=(m/n);
	for(int i=1;i<=q;i++){
		x=read();y=read();
		if(rev)swap(x,y);
		HM::add(x,y);
	}
	memset(f,-10,sizeof(f));
	f[F(1,0)]=1;
	for(int i=1;i<=n;i++){
		for(int k=0;k<maxx;k++){
			int tmp=f[F(i,k)];
			if(tmp<0)continue;
			int tx=i+tmp+HM::query(i,tmp);
			f[F(i,k+1)]=Max(f[F(i,k+1)],min(tx,m));
			f[F(min(tx,n),k+1)]=Max(f[F(min(tx,n),k+1)],f[F(i,k)]);
		}
	}
	int ans=1e9;
	for(int k=0;k<=maxx;k++){
		if(f[F(n,k)]>=m){
			ans=min(ans,k);
		}
	}
	cout<<ans;
	return 0;
}