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
const int N=2e5+5;
const int M=4e5+5;
int n,m,x,y;
string s;
int bit[M+5],id[M+5],siz[M+5],ch[M+5][2],fu[M+5],rev[M+5],col[N],tot;
vi v[N];
void add(int x,int k){
	for(;x<M;x+=(x&(-x)))bit[x]+=k;
}
int query(int x){
	int tmp=0;
	for(;x;x-=(x&(-x)))tmp+=bit[x];
	return tmp;
}
int st[N],top;
#define ls ch[u][0]
#define rs ch[u][1]
bool isroot(int u){
	return !((ch[fu[u]][0]==u)||(ch[fu[u]][1]==u));
}
void pushdown(int u){
	if(rev[u]){
		rev[ls]^=1;
		rev[rs]^=1;
		swap(ch[ls][0],ch[ls][1]);
		swap(ch[rs][0],ch[rs][1]);
		rev[u]=0;
	}
	id[ls]=id[u];
	id[rs]=id[u];
}
void update(int u){
	siz[u]=siz[ls]+siz[rs]+1;
}
void roate(int u){
	int y=fu[u];
	int z=fu[y];
	int h=(ch[y][1]==u);
	int k=(ch[u][!h]);
	if(!isroot(y))ch[z][ch[z][1]==y]=u;
	fu[u]=z;fu[y]=u;if(k)fu[k]=y;
	ch[y][h]=k;ch[u][h^1]=y;
	update(y);update(u);
}
void splay(int u){
	top=0;
	int tmp=u;
	while(!isroot(tmp)){
		st[++top]=tmp;
		tmp=fu[tmp];
	}
	st[++top]=tmp;
	while(top){
		pushdown(st[top--]);
	}
	while(!isroot(u)){
		int y=fu[u];
		if(!isroot(y)){
			int z=fu[y];
			if(((ch[z][1]==y)^(ch[y][1]==u))==0)roate(y);
			else roate(u);
		}
		roate(u);
	}
	update(u);
}
void access(int u){
	tot++;
	for(int pre=0;u;u=fu[u]){
		splay(u);
		add(id[u],-(siz[ls]+1));
		add(tot,siz[ls]+1);
		
		ch[u][1]=pre;
		update(u);pre=u;
	}
}
void makeroot(int u){
	access(u);
	splay(u);
	swap(ls,rs);
	rev[u]^=1;
	id[u]=tot;
}
int ask(int u){
	splay(u);
	return query(id[u]-1)+siz[u]-siz[ls];
}
void dfs(int u,int fa){
	fu[u]=fa;siz[u]=1;id[u]=u;
	for(auto i:v[u]){
		if(i==fa)continue;
		dfs(i,u);
		if(id[i]>id[u]){
			id[u]=id[i];
			ch[u][1]=i;
			siz[u]=siz[i]+1;
		}
	}
	add(id[u],1);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	int fx,fy;
	for(int i=1;i<n;i++){
		x=read();y=read();
		if(i==1)fx=x,fy=y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(n,0);tot=n;
	for(int i=1;i<=m;i++){
		cin>>s;
		if(s=="up"){
			x=read();
			makeroot(x);
		}
		if(s=="when"){
			x=read();
			cout<<ask(x)<<'\n';
		}
		if(s=="compare"){
			x=read();y=read();
			int tx=ask(x);
			int ty=ask(y);
			cout<<(tx<ty?x:y)<<'\n';
		}
	}
	return 0;
}