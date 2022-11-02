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
const int N=2e5+5;
int T,n;
struct node{
	int id,val;
}a[N],b[N];
int cmp(node x,node y){
	return x.val<y.val;
}
int f[N],in[N];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return ;
	f[y]=x;
}
vi v[N];
int dfn[N],low[N],tot,vis[N],st[N],las[N],top;
void tarjan(int u){
	st[++top]=u;dfn[u]=low[u]=++tot;
	for(auto i:v[u]){
		if(!dfn[i]){
			tarjan(i);
			low[u]=min(low[u],low[i]);
		}
		else if(!vis[i])low[u]=min(low[u],dfn[i]);
	}
	if(dfn[u]==low[u]){
		while(st[top]!=u){
			merge(u,st[top]);
			vis[st[top]]=1;
			top--;
		}
		vis[u]=1;
		top--;
	}
}
void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].val=read();
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		b[i].val=read();
		b[i].id=i;
		f[i]=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(int i=2;i<=n;i++){
		v[a[i].id].pb(a[i-1].id);
	}
	for(int i=2;i<=n;i++){
		v[b[i].id].pb(b[i-1].id);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=2;i<=n;i++){
		int x=find(a[i].id);
		int y=find(a[i-1].id);
		if(x==y)continue;
		in[y]++;
	}
	for(int i=2;i<=n;i++){
		int x=find(b[i].id);
		int y=find(b[i-1].id);
		if(x==y)continue;
		in[y]++;
	}
	int tmp=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(find(i)==i && !in[find(i)]){
			tmp=find(i);cnt++;
		}
	}
	if(cnt==1){
		for(int i=1;i<=n;i++){
			if(find(i)==tmp){
				cout<<1;
			}
			else cout<<0;
		}
	}
	else{
		for(int i=1;i<=n;i++)cout<<0;
	}
	cout<<'\n';
	tot=0;
	for(int i=1;i<=n;i++)vis[i]=dfn[i]=low[i]=st[i]=in[i]=0;
	for(int i=1;i<=n;i++)v[i].clear();
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		solve();
	}
	return 0;
}