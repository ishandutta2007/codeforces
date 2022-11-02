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
const int N=505;
int n;
struct node{
	int a,b,k;
}a[N];
int cmp(node x,node y){
	return x.b>y.b;
}
int f[N][N];
signed main(){
	#ifdef newbiewzs
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++){
		a[i].a=read();
		a[i].b=read();
		a[i].k=read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int k=0;k<=i;k++){
			f[i][k]=f[i-1][k];
			f[i][k]=max(f[i][k],f[i-1][k]+(a[i].a-a[i].b*a[i].k));
			if(i==2 && k==2){
				new char;
			}
			if(k)f[i][k]=max(f[i][k],f[i-1][k-1]+a[i].a-a[i].b*min(k-1,a[i].k));
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,f[n][i]);
	cout<<ans;
	return 0;
}