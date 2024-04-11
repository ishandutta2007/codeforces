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

int n;

int vv[100010];
vector<int> ep[100010];
vector<int> ec[100010];
multiset<ll> vs;
int ans=0;
int par[100010];

int dfs(int x,ll dst){
	vs.insert(dst);
	int sz=ep[x].size();
	int tsize = 1;
	for(int i=0; i<sz; ++i){
		int y=ep[x][i];
		if(y == par[x]) continue;
		par[y]=x;
		int dd=ec[x][i];
		tsize += dfs(y, dst+dd);
	}

	{
		auto it = vs.lower_bound(dst-vv[x]);
		if(it != vs.begin()){
			ans += tsize;
			tsize = 0;
		}
	}
	vs.erase(vs.find(dst));
	return tsize;
}

int main(){
	read(n);
	for(int i=1; i<=n; ++i) read(vv[i]);
	for(int i=2; i<=n; ++i){
		int a,b;
		read(a,b);
		ep[a].pb(i); ec[a].pb(b);
		ep[i].pb(a); ec[i].pb(b);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}