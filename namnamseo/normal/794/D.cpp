#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n, z;

vector<int> e[300010];

map<vector<int>,int> m;

int par[300010];
int root(int x){ return (x==par[x])?x:(par[x]=root(par[x])); }

vector<int> f[300010];

int cn;
int col[300010];
vector<int> g[300010];

int main()
{
	read(n, z);
	for(int i=1; i<=z; ++i){
		int a, b; read(a, b); e[a].pb(b); e[b].pb(a);
	}
	for(int i=1; i<=n; ++i) par[i]=i;
	for(int i=1; i<=n; ++i){
		e[i].pb(i);
		sort(all(e[i]));
		int& r=m[e[i]];
		if(r) par[root(r)]=root(i);
		r=root(i);
	}
	for(int i=1; i<=n; ++i) for(int j:e[i]) if(root(i)!=root(j)){
		f[root(i)].eb(root(j)); f[root(j)].eb(root(i));
	}
	int hashi = -1;
	for(int i=1; i<=n; ++i) if(i==par[i]){
		int c[2]={-1, -1};
		for(int j:f[i]){
			if(c[0] == -1) c[0]=j;
			else if(c[0] != j){
				if(c[1] != j && c[1] != -1){
					puts("NO");
					return 0;
				} else c[1]=j;
			}
		}
		if(c[0] != -1) g[i].pb(c[0]);
		if(c[1] == -1) hashi=i; else g[i].pb(c[1]);
	}
	if(hashi == -1){
		puts("NO"); return 0;
	}
	int p=hashi;
	for(bool f=1;f;){
		col[p] = ++cn;
		f=0;
		for(int y:g[p]){
			if(!col[y]){
				p=y;
				f=1;
				break;
			}
		}
	}
	for(int i=1; i<=n; ++i) if((i==par[i]) && (!col[i])){
		puts("NO"); return 0;
	}
	puts("YES");
	for(int i=1; i<=n; ++i){
		printf("%d ", col[root(i)]);
	}
	return 0;
}