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

int par[100010];
int root(int x){ return (x==par[x])?x:(par[x]=root(par[x])); }

int n;

vector<int> e[100010];
multiset<int> far[100010];
int nuke[100010];
bool cen[100010];
unordered_map<int,int> dpm[100010];
int get(int x, int from){
	auto it = dpm[x].find(from);
	if(it != dpm[x].end()) return it->second;
	if(cen[x]){
		far[x].insert(get(nuke[x], x)+1);
		far[x].erase(far[x].find(get(from, x)+1));
	} else {
		for(int y:e[x]) if(y != from){
			far[x].insert(get(y, x) + 1);
		}
	}
	cen[x]=1; nuke[x]=from;
	return dpm[x][from] = (far[x].empty() ? 0 : *--far[x].end());
}
int most[100010];

int diam[100010];
vector<int> cnt[100010];
vector<ll> wei[100010];

map<int,double> cache[100010];

ll rsum(auto& v, int l, int r){
	if(l>r) return 0;
	ll ret = v[r];
	if(l) ret -= v[l-1];
	return ret;
}

int main()
{
	int m, Q;
	read(n, m, Q);
	for(int i=1; i<=n; ++i) par[i]=i;
	for(int i=0; i<m; ++i){
		int a, b; read(a, b);
		par[root(b)]=root(a);
		e[a].pb(b); e[b].pb(a);
	}
	for(int i=1; i<=n; ++i){
		for(int j:e[i]) most[i]=max(most[i], get(j, i) + 1);
		int r = root(i);
		diam[r] = max(diam[r], most[i]);
	}
	for(int i=1; i<=n; ++i) if(i == par[i]){
		cnt[i].resize(diam[i] + 1);
		wei[i].resize(diam[i] + 1);
	}
	for(int i=1; i<=n; ++i){
		int r = root(i), k = most[i];
		cnt[r][k] += 1;
		wei[r][k] += k;
	}
	for(int i=1; i<=n; ++i) if(i == par[i]){
		int cs=0; ll ws=0;
		/*printf("Component of %d : diam %d\n", i, diam[i]);
		for(int j=0; j<=diam[i]; ++j){
			printf("%d ", cnt[i][j]);
		}
		putchar(10);*/
		for(int& x:cnt[i]){ cs+=x; x=cs; }
		for(ll& x:wei[i]){ ws+=x; x=ws; }
	}
for(;Q--;){
	int a, b; read(a, b);
	a = root(a); b = root(b);
	if(a == b){
		puts("-1"); continue;
	}
	if(diam[a]>diam[b]) swap(a, b);
	auto it = cache[a].find(b);
	if(it != cache[a].end()){
		printf("%.10f\n", it->second);
		continue;
	}
	int da = diam[a];
	int targ = diam[b];
	double ans = 0;
	ll pcnt = cnt[a][da] * 1LL * cnt[b][targ];
	for(int i=0; i<=da; ++i){
		int koe = targ - i;
		ll uc = rsum(cnt[b], koe, targ);
		ll us = rsum(wei[b], koe, targ);
		int mc = (i ? cnt[a][i] - cnt[a][i-1] : cnt[a][0]);
		ans += (us + (i+1) * uc) * 1.0 * mc;
		ans += rsum(cnt[b], 0, koe-1) * 1.0 * mc * 1.0 * targ;
	}
	printf("%.10f\n", cache[a][b] = ans/pcnt);
}
	return 0;
}