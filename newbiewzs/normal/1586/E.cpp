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
const int N=3e5+5;
int T,n,m,x,y,vis[N],q,minn[N],deep[N],fu[N];
vi g[N],v[N],ans[N];
int st[N],top,sa[N],head;
void dfs(int u,int fa){
	vis[u]=1;deep[u]=deep[fa]+1;fu[u]=fa;
	for(auto i:g[u]){
		if(vis[i])continue;
		dfs(i,u);
		v[u].pb(i);
	}
}
void dfs1(int u){
	minn[u]=fu[u];
	for(auto i:g[u]){
		if(deep[i]<deep[minn[i]])minn[i]=i;
	}
	for(auto i:v[u]){
		dfs1(i);
	}
}
int lca(int x,int y){
	while(x!=y){
		if(deep[x]<deep[y])swap(x,y);
		x=fu[x];
	}
	return x;
}
int zs[N];
void solve(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();
		g[x].pb(y);g[y].pb(x);
	}
	dfs(1,0);
	dfs1(1);q=read();
	for(int i=1;i<=q;i++){
		x=read();y=read();
		zs[x]++;
		zs[y]++;
	//	if(deep[x]<deep[y])swap(x,y);
		int L=lca(x,y);
		top=0;
		while(1){
			st[++top]=x;
			if(x==L)break;
			x=fu[x];
		}
		head=0;
		while(1){
			if(y==L)break;
			sa[++head]=y;
			y=fu[y];
		}
		while(head){
			st[++top]=sa[head];
			head--;
		}
		for(int k=1;k<=top;k++){
			ans[i].pb(st[k]);
		}
	}
	int summ=0;
	for(int i=1;i<=n;i++){
		if(zs[i]%2==1)summ++;
	}
	if(summ){
		cout<<"NO"<<'\n';
		cout<<summ/2;
		return ;
	}
//	dp(1);
	cout<<"YES"<<'\n';
	for(int i=1;i<=q;i++){
		cout<<ans[i].size()<<'\n';
		for(auto k:ans[i]){
			cout<<k<<" ";
		}
		cout<<'\n';
	}
}
int main(){
	#ifdef newbiewzs
	#else
	#endif
//	cin>>T;
	T=1;
	while(T--){
		solve();
	}
	return 0;
}