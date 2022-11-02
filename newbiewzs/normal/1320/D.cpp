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
// #pragma GCC optimize(3)
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
const int mod1=998244353;
const int mod2=1e9+7;
const int h=233;
const int N=3e5+5;
char c[N];
int a[N],n,m,l,L,len,s[N],sa[N],sb[N],pa[N],pb[N],ka[N],kb[N];
#define calc(l,r) (s[r]-s[l-1])
int solve1(int l,int r,int id){
	if(l>r)return 0;
	if(id==1)return (sa[r]-1ll*sa[l-1]*pa[calc(l,r)]%mod1+mod1)%mod1;
	else return (ka[r]-1ll*ka[l-1]*pa[calc(l,r)]%mod1+mod1)%mod1;
}
int solve2(int l,int r,int id){
	if(l>r)return 0;
	if(id==1)return (sb[r]-1ll*sb[l-1]*pb[calc(l,r)]%mod2+mod2)%mod2;
	else return (kb[r]-1ll*kb[l-1]*pb[calc(l,r)]%mod2+mod2)%mod2;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)a[i]=c[i]-'0';
	pa[0]=pb[0]=1;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			sa[i]=(1ll*sa[i-1]*h+(i%2+1)%mod1)%mod1;
			sb[i]=(1ll*sb[i-1]*h+(i%2+1)%mod2)%mod2;
			ka[i]=(1ll*ka[i-1]*h+((i+1)%2+1)%mod1)%mod1;
			kb[i]=(1ll*kb[i-1]*h+((i+1)%2+1)%mod2)%mod2;
			s[i]=s[i-1]+1;
		}
		else ka[i]=ka[i-1],kb[i]=kb[i-1],sa[i]=sa[i-1],sb[i]=sb[i-1],s[i]=s[i-1];
		pa[i]=1ll*pa[i-1]*h%mod1;
		pb[i]=1ll*pb[i-1]*h%mod2;
	}
	m=read();
	for(int i=1;i<=m;i++){
		l=read();L=read();len=read();
		if(solve1(l,l+len-1,l%2)!=solve1(L,L+len-1,L%2) || solve2(l,l+len-1,l%2)!=solve2(L,L+len-1,L%2) || (s[l+len-1]-s[l-1] != s[L+len-1]-s[L-1]))puts("No");
		else puts("Yes");
	}
	return 0;
}