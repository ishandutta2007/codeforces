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

int n, m;

int col[300010];
vector<int> my[300010];
vector<int> e[300010];

int p[300010];

void dfs(int x){
	unordered_set<int> s;
	for(int c:my[x]){
		if(col[c]) s.insert(col[c]);
	}
	int cc=1;
	for(int c:my[x]){
		if(!col[c]){
			while(s.find(cc) != s.end()) ++cc;
			s.insert(cc);
			col[c] = cc;
		}
	}
	for(int y:e[x]){
		if(p[x] == y) continue;
		p[y]=x;
		dfs(y);
	}
}

int main()
{
	read(n, m);
	for(int i=1; i<=n; ++i){
		int s; read(s);
		auto& v=my[i]; v.reserve(s);
		for(;s--;){
			int t; read(t); v.pb(t);
		}
	}
	for(int i=1; i<n; ++i){
		int a, b; read(a, b);
		e[a].pb(b); e[b].pb(a);
	}
	
	dfs(1);
	for(int i=1; i<=m; ++i) if(!col[i]) col[i]=1;
	printf("%d\n", *max_element(col+1, col+m+1));
	for(int i=1; i<=m; ++i) printf("%d ", col[i]);
	
	return 0;
}