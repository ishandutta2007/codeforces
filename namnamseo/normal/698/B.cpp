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
void read(ll& x){ cin >> x; }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int n;
int out[200010];

bool vis[200010];
bool onstk[200010];

vector<int> tc;

void dfs(int x){
	onstk[x]=true;
	vis[x]=true;
	int y=out[x];
	if(!vis[y]) dfs(y);
	else if(onstk[y]){
		tc.pb(x);
	}
	onstk[x]=false;
}

int main(){
	read(n);
	for(int i=1; i<=n; ++i) read(out[i]);
	for(int i=1; i<=n; ++i) if(!vis[i]) dfs(i);
	if(sz(tc) == 0){
		for(int i=1; i<=n; ++i) printf("%d ",out[i]);
		return 0;
	}
	int r=-1;
	for(int a:tc) if(out[a]==a){ r=a; break; }
	int ans=0;
	if(r == -1){
		for(int a:tc){
			++ans;
			r=a;
			out[a]=a;
			break;
		}
	}
	for(int a:tc) if(a!=r){
		++ans;
		out[a]=r;
	}
	printf("%d\n", ans);
	for(int i=1; i<=n; ++i) printf("%d ",out[i]);
	return 0;
}