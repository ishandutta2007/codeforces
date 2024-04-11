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
#define m0(x,n) memset(x,0,sizeof(int)*(n+5))
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
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
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
const int N=2050;
const int mod=1e9+7;
int T,n,sa[N],sb[N];
char a[N],b[N];
int f[N][N],g[N][N],s[N][N];
inline int add(const int &x,const int &y){
	return (x+y>=mod?x+y-mod:x+y);
}
inline int del(const int &x,const int &y){
	return (x-y<0?x-y+mod:x-y);
}
int calc(int x,int y,int xx,int yy){
	if(x>xx || y>yy)return 0;
	int ta=(y>0?s[xx][y-1]:0);
	int tb=(x>0?s[x-1][yy]:0);
	int tc=((x>0 && y>0)?s[x-1][y-1]:0);
	return del(add(s[xx][yy],tc),add(ta,tb));
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		for(int i=1;i<=n;i++){
			m0(f[i],n);
			m0(g[i],n);
			sa[i]=sb[i]=-1;
			if(i&1){
				if(a[i]=='0')a[i]='1';
				else if(a[i]=='1')a[i]='0';
				if(b[i]=='0')b[i]='1';
				else if(b[i]=='1')b[i]='0';
			}
		}
		sa[0]=sb[0]=1;
		for(int i=1;i<=n;i++){
			if(a[i]=='0' || a[i]=='?'){
				sa[i]=i;
				if(a[i-1]=='0' || a[i-1]=='?')sa[i]=sa[i-1];
			}
			if(b[i]=='0' || b[i]=='?'){
				sb[i]=i;
				if(b[i-1]=='0' || b[i-1]=='?')sb[i]=sb[i-1];
			}
		}
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				s[i][k]=del(add(s[i-1][k],s[i][k-1]),s[i-1][k-1]);
				if(a[i]=='0' || b[k]=='0'){
					continue;
				}
				if(sa[i-1]==1 && sb[k-1]==1)f[i][k]=1;
				int x=sa[i-1];
				int y=sb[k-1];
				if(x==-1)x=i-1;
				else x=x-1;
				if(y==-1)y=k-1;
				else y=y-1;
				if(x<i && y<k){
					int tmp=calc(x,y,i-1,k-1);
					f[i][k]=add(f[i][k],tmp);
				}
				s[i][k]=add(s[i][k],f[i][k]);
			}
		}
		reverse(a+1,a+n+1);reverse(b+1,b+n+1);
		for(int i=1;i<=n;i++)sa[i]=sb[i]=-1;
		for(int i=1;i<=n;i++){
			if(a[i]=='0' || a[i]=='?'){
				sa[i]=i;
				if(a[i-1]=='0' || a[i-1]=='?')sa[i]=sa[i-1];
			}
			if(b[i]=='0' || b[i]=='?'){
				sb[i]=i;
				if(b[i-1]=='0' || b[i-1]=='?')sb[i]=sb[i-1];
			}
		}
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				s[i][k]=del(add(s[i-1][k],s[i][k-1]),s[i-1][k-1]);
				if(a[i]=='0' || b[k]=='0'){
					continue;
				}
				if(sa[i-1]==1 && sb[k-1]==1)g[i][k]=1;
				int x=sa[i-1];
				int y=sb[k-1];
				if(x==-1)x=i-1;
				else x=x-1;
				if(y==-1)y=k-1;
				else y=y-1;
				int tmp=calc(x,y,i-1,k-1);
				g[i][k]=add(g[i][k],tmp);
				s[i][k]=add(s[i][k],g[i][k]);
			}
		}
		reverse(a+1,a+n+1);reverse(b+1,b+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				if(a[i]=='0' || b[k]=='0')continue;
				ans=add(ans,1ll*abs(i-k)*f[i][k]%mod*g[n-i+1][n-k+1]%mod);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}