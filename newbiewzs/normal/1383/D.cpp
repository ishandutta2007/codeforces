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
const int N=255;
int n,m,a[N][N],r[N],c[N],st[N*N],top;
bool pa[N*N],pb[N*N];
int da[N][N],sx[N*N],sy[N*N];
#define id(x,y) ((x-1)*m+y)
vector<pii>p;
int mx[N],my[N];
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			a[i][k]=read();
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++)r[i]=max(r[i],a[i][k]);
		pa[r[i]]=1;
	}
	for(int i=1;i<=m;i++){
		for(int k=1;k<=n;k++)c[i]=max(c[i],a[k][i]);
		pb[c[i]]=1;
	}
	int tx=0,ty=0;
	for(int i=n*m;i>=1;i--){
		if(!pa[i] && !pb[i]){
			st[++top]=i;
		}
		if(pa[i] && pb[i]){
			tx++;ty++;
			da[tx][ty]=i;
			p.pb(mp(tx,ty));
			mx[tx]=i;
			my[ty]=i;
		}
		if(pa[i] && !pb[i]){
			tx++;
			da[tx][ty]=i;
			p.pb(mp(tx,ty));
			mx[tx]=i;
		}
		if(!pa[i] && pb[i]){
			ty++;
			da[tx][ty]=i;
			p.pb(mp(tx,ty));
			my[ty]=i;
		}
	}
	int top=1;
	for(auto i:p){
		int x=i.fi;
		int y=i.se;
		if(y>1 && da[x-1][y-1] && my[y]>st[top] && mx[x]>st[top]){
			for(int k=x-1;k>=1;k--){
				if(da[k][y])break;
				da[k][y]=st[top++];
			}
		}
		if(da[x-1][y-1] && my[y-1]>st[top] && mx[x]>st[top]){
			for(int k=y-1;k>=1;k--){
				if(da[x][k])break;
				da[x][k]=st[top++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			cout<<da[i][k]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}