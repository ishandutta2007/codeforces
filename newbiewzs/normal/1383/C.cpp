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
const int N=1e5+5;
int T,n,ans,a[N],b[N],f[N],g[21],s[1<<20];
char aa[N],bb[N];
inline int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();
		scanf("%s",aa+1);
		scanf("%s",bb+1);
		for(int i=1;i<=n;i++){
			a[i]=aa[i]-'a'+1;
			b[i]=bb[i]-'a'+1;
			g[a[i]]|=(1<<(b[i]-1));
		}
		for(int i=1;i<=20;i++)f[i]=i;
		for(int i=1;i<=n;i++){
			f[find(a[i])]=find(b[i]);
		}
		ans=40;
		for(int i=1;i<=20;i++)if(find(i)==i)ans--;
		s[0]=1;int maxx=0;
		for(int i=0;i<(1<<20);i++){
			if(!s[i])continue;
			maxx=max(maxx,bc(i));
			for(int k=1;k<=20;k++){
				if(i&(1<<(k-1)))continue;
				if((g[k]&i))continue;
				s[i|(1<<(k-1))]=1;
			}
		}
		cout<<ans-maxx<<'\n';
		mem0(g);
		mem0(f);
		mem0(s);
	}
	return 0;
}