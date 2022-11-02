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
int T,n,m,a[19],f[19],g[19];
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		memset(f,0,sizeof(f));
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=read(),f[a[i]]=1;
		for(int i=1;i<18;i++){
			if(f[i]==0){
				f[i]=f[i-1]*10;
			}
		}
		for(int i=1;i<=18;i++){
			int x=0,tmp=m+1;
			memset(g,0,sizeof(g));
			for(int k=0;k<=i-1;k++)g[k]=g[k-1]+f[k]*9;
			bool flag=0;
			for(int k=i-1;k>=0;k--){
				flag=0;
				if(k==0){
					for(int j=0;j<=9;j++){
						if(f[k]*j>=tmp){
							tmp-=f[k]*j;
							x=x*10;
							x+=j;
							flag=1;
							break;
						}
					}
				}
				else{
					for(int j=0;j<=9;j++){
						if(f[k]*j+g[k-1]>=tmp){
							tmp-=f[k]*j;
							x=x*10;
							x+=j;
							flag=1;
							break;
						}
					}
				}
				if(!flag)break;
			}
			if(flag){
				cout<<x<<'\n';
				break; 
			}
		} 
	}
	return 0;
}