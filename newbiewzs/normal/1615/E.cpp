
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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	#ifdef WIN
		#include<windows.h>
		int cnt=0;
		template<typename T>
		T debug(T x){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		  	cerr<<x<<" ";
		  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}
		template<typename T,typename ...Types>
		void debug(T x,Types ... y){
			cnt++;int tmp=cnt;
			debug(x);
			debug(y...);
			if(tmp==cnt)cerr<<'\n';
		}
	#else
		// Linux
		/*#define Green \033[32m
		#define Reset \033[0m\n
		void debug(int x){
			cout<<"Green"<<x<<"Reset";
		}*/
	#endif
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
const int N=3e5+5;
int n,x,y,m,ans;
vi v[N];
int deep[N],dfn[N],ed[N],p[N],tot,st[N],bj[N],fu[N],top;
void dfs(int u,int fa){
	dfn[u]=++tot;deep[u]=deep[fa]+1;int siz=0;
	p[tot]=u;fu[u]=fa;
	for(auto i:v[u]){
		if(i==fa)continue;siz++;
		dfs(i,u);
	}
	if(!siz)st[++top]=u,bj[u]=1;
	ed[u]=tot;
}
int maxx[N*4],id[N*4],tag[N*4],pd[N],R[N],L[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void pushdown(int u){
	if(!tag[u])return ;
	maxx[ls]+=tag[u];
	maxx[rs]+=tag[u];
	tag[ls]+=tag[u];
	tag[rs]+=tag[u];
	tag[u]=0;
}
void update(int u){
	maxx[u]=max(maxx[ls],maxx[rs]);
	if(maxx[u]==maxx[ls])id[u]=id[ls];
	else id[u]=id[rs];
}
void build(int u,int l,int r){
	if(l==r){
		if(!bj[p[l]])maxx[u]=-1e9;
		else maxx[u]=deep[p[l]];
		id[u]=p[l];
		return ;
	} 
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(u);
}
void add(int u,int l,int r,int L,int R,int k){
	if(L>R)return ;
	if(L<=l && R>=r){
		maxx[u]+=k;
		tag[u]+=k;
		return ;
	}
	pushdown(u);
	if(L<=mid)add(ls,l,mid,L,R,k);
	if(R>mid)add(rs,mid+1,r,L,R,k); 
	update(u);
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<n;i++){
		x=read();y=read();
		v[x].pb(y);
		v[y].pb(x); 
	}
	dfs(1,0);
	build(1,1,n);
	if(m>top){
		int ans=0;
		for(int i=top;i<=m;i++){
			ans=max(ans,(n-i)*i);
		}
		cout<<ans;
		return 0;
	}
	int summ=n,ans=-1e18,zs=0;
	for(int i=1;i<=n;i++){
		L[i]=dfn[i];
		R[i]=ed[i];
	}
	for(int i=1;i<=m;i++){
		int pos=id[1];
		summ-=maxx[1];
		zs+=(maxx[1]-1);
		add(1,1,n,dfn[pos],ed[pos],-1e9);
		int u=fu[pos],pre=pos;
		while(u){
			if(pd[u]==1)break;
			pd[u]=1;
			add(1,1,n,dfn[u],ed[u],-1);
			pre=u;
			u=fu[u];
		}
		if(i-summ<0 && abs(i-summ)>zs){
			int tmp=abs(i-summ)-zs;
			int ta=(i-summ)+tmp/2;
			int tb=zs+tmp/2;
			ans=max(ans,ta*tb);
		}
		else ans=max(ans,(i-summ)*zs);
	}
	cout<<ans;
	return 0;
}