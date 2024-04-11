#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define pb emplace_back
#define mp std::make_pair
#define fi first
#define se second
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vll;
typedef vector<pii>vpii;
template<typename T>T cmax(T &x, T y){return x=x>y?x:y;}
template<typename T>T cmin(T &x, T y){return x=x<y?x:y;}
template<typename T>
T &read(T &r){
	r=0;bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();
	while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();
	return r=w?-r:r;
}
template<typename T1,typename... T2>
void read(T1 &x, T2& ...y){ read(x); read(y...); }
const int N=400010;
int n,m,s,fa[N],vis[N],dep[N],blo[N];
vi eg[N],a,b;
void Answ(){
	cout << a.size() << '\n';
	for(auto x:a)cout << x << ' ';
	puts("");
	cout << b.size() << '\n';
	for(auto x:b)cout << x << ' ';
	puts("");
	exit(0);
}
void dfs(int x,int f,int t){
	fa[x]=f;
	dep[x]=dep[f]+1;
	blo[x]=t;
	for(auto v:eg[x]){
		if(v==f)continue;
		if(s==x&&dep[v]){
			puts("Possible");
			a.pb(s);a.pb(v);
			int y=v;
			while(y)b.pb(y),y=fa[y];
			reverse(b.begin(),b.end());
			Answ();
		}
		if(dep[v]){
			if(blo[v]!=blo[x]&&v!=s){
				puts("Possible");
				a.pb(v);while(x)a.pb(x),x=fa[x];
				while(v)b.pb(v),v=fa[v];
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				Answ();
			}
			continue;
		}
		if(s==x){
			dfs(v,x,v);
		}
		else{
			dfs(v,x,t);
		}
	}
}
signed main(){
	read(n,m,s);
	for(int i=1;i<=m;i++){
		int u,v;
		read(u,v);
		eg[u].pb(v);
	}
	dfs(s,0,0);
	puts("Impossible");
    #ifdef qawszx
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}