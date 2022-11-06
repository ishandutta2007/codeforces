#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int color[100010];
vector<int> edge[100010];

bool dfs(int x,int c){
	if(color[x] && (color[x] != c)) return false;
	if(color[x]) return true;
	color[x] = c;
	for(int y:edge[x]){
		if(!dfs(y, 3-c)) return false;
	}
	return true;
}

int main(){
	int n,m;
	read(n,m);
	for(;m--;){
		int a,b;
		read(a,b);
		edge[a].pb(b); edge[b].pb(a);
	}
	for(int i=1; i<=n; ++i){
		if(!color[i]){
			if(!dfs(i,1)){
				puts("-1");
				return 0;
			}
		}
	}
	vector<int> cs[3];
	for(int i=1; i<=n; ++i){
		cs[color[i]].pb(i);
	}
	for(int i=1; i<=2; ++i){
		auto& v=cs[i];
		printf("%d\n",int(v.size()));
		for(int t:v) printf("%d ",t);
		putchar(10);
	}
	return 0;
}