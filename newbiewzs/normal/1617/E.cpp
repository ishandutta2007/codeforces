#pragma GCC optimize(3)
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
#include<unordered_map>
#include<unordered_set>
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
const int N=2e5+5;
int n,a[N],tot,g[N][35],sd[N];
map<pii,int>ma;
int lca(int x,int y){
	for(int i=0;i<=sd[x];i++){
		if(ma.count(mp(y,g[x][i]))){
			return i+ma[mp(y,g[x][i])]; 
		}
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	// I'm a SB
	for(int i=1;i<=n;i++){
		int tmp=a[i],deep=0;
		while(tmp){
			g[i][deep]=tmp;
			ma[mp(i,tmp)]=deep;
			if(bc(tmp)==1)tmp=0;
			else{
				int bit;
				for(int k=30;k>=0;k--){
					if(tmp&(1<<k)){
						bit=k;break;
					}
				}
				tmp=(1<<(bit+1))-tmp;
			}
			deep++;
		}
		g[i][sd[i]=deep]=tmp;
		ma[mp(i,tmp)]=deep;
	}
	int maxx=0,pos=-1;
	for(int i=2;i<=n;i++){
		if(lca(1,i)>maxx){
			maxx=lca(1,i);
			pos=i;
		}
	}
	int pa=0;
	for(int i=1;i<=n;i++){
		if(i==pos)continue;
		int tmp=lca(pos,i);
		if(tmp>=maxx){
			maxx=tmp;
			pa=i;
		}
	}
	cout<<pa<<" "<<pos<<" "<<maxx;
	return 0;
}