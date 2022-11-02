#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <bitset>
#include <set>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
ll n, m, k;
vector<pii> adj[sz];
int deg[sz], ans[sz];
vector<pii> e;
bitset<sz> bad, marked;

int main() {
	fast;
	scanf("%d %d %d", &n, &m, &k);
	int a, b;
	foru(i, 0, m) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb({ b,i });
		adj[b].pb({ a,i });
		deg[a]++; deg[b]++;
		e.pb({ a,b });
	}
	set<pii> s;
	foru(i, 0, n)s.insert({ deg[i],i });
	int good = n;
	while (!s.empty()) {
		if (s.begin()->first >= k)break;
		pii p = *s.begin(); s.erase(p);
		int ind = p.second;
		if (bad[ind])continue;
		bad[ind] = 1;
		good--;
		for (auto x : adj[ind]) {
			if (marked[x.second])continue;
			marked[x.second] = 1;
			s.erase({ deg[ind],ind });
			s.erase({ deg[x.first],x.first });
			deg[ind]--;
			deg[x.first]--;
			if (!bad[x.first]) s.insert({ deg[x.first],x.first });
		}
	}
	ans[m] = good;
	ford(i, m - 1, 0) {
		a = e[i].first, b = e[i].second;
		if (!marked[i]) {
			marked[i] = 1;
			s.erase({ deg[a]--,a });
			s.erase({ deg[b]--,b });
			if (!bad[a])s.insert({ deg[a],a });
			if (!bad[b])s.insert({ deg[b],b });
			while (!s.empty()) {
				if (s.begin()->first >= k)break;
				pii p = *s.begin(); s.erase(p);
				int ind = p.second;
				if (bad[ind])continue;
				bad[ind] = 1;
				good--;
				for (auto x : adj[ind]) {
					if (marked[x.second])continue;
					marked[x.second] = 1;
					s.erase({ deg[ind],ind });
					s.erase({ deg[x.first],x.first });
					deg[ind]--;
					deg[x.first]--;
					if (!bad[x.first]) s.insert({ deg[x.first],x.first });
				}
			}
		}
		ans[i] = good;
	}
	for (int i = 1; i <= m; i++)printf("%d\n", ans[i]);
	return 0;
}