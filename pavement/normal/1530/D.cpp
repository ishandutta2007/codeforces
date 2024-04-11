#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define ii pair<int, int>
#define mp make_pair

int T, N, a[200005], link[200005], sz[200005], out[200005];
bool oncyc[200005];
ii pp[200005];
vector<int> adj[200005];

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

void go(int x) {
	if (adj[x].empty()) return;
	out[adj[x][0]] = x;
	for (auto u : adj[x]) go(u);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			link[i] = i;
			sz[i] = 1;
			oncyc[i] = 0;
			out[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			cin >> a[i];
			adj[a[i]].pb(i);
			unite(i, a[i]);
		}
		for (int i = 1; i <= N; i++) {
			if (i != find(i)) continue;
			int hare = i, tort = i;
			do {
				hare = a[a[hare]];
				tort = a[tort];
			} while (hare != tort);
			do {
				oncyc[tort] = 1;
				tort = a[tort];
			} while (hare != tort);	
		}
		for (int i = 1; i <= N; i++) {
			if (oncyc[a[i]] && !oncyc[i]) go(i);
			else if (oncyc[i]) out[i] = a[i];
		}
		int k = 0;
		set<int> tmps;
		vector<int> tmp, pos;
		for (int i = 1; i <= N; i++) tmps.insert(i);
		for (int i = 1; i <= N; i++) {
			if (out[i]) {
				assert(tmps.count(out[i]));
				tmps.erase(out[i]);
			} else pos.pb(i);
		}
		for (int i : tmps) tmp.pb(i);
		assert(pos.size() == tmp.size());
		if (tmp.size() == 1) {
			int tmp2 = 0, tmp3 = -1, tmp4 = 0, tmp5 = -1;
			for (int i = 1; i <= N; i++) {
				if (adj[i].empty()) tmp2++, tmp3 = i;
				if (oncyc[a[i]] && !oncyc[i]) tmp4++, tmp5 = i;
			}
			assert(tmp2 == 1 && tmp4 == 1);
			out[tmp5] = a[tmp5];
			assert(adj[a[tmp5]].size() == 2);
			if (adj[a[tmp5]][0] == tmp5) out[adj[a[tmp5]][1]] = tmp3;
			else out[adj[a[tmp5]][0]] = tmp3;
		} else {
			sort(pos.begin(), pos.end());
			for (int i = 0; i < tmp.size(); i++)
				pp[i] = mp(-1ll, -1ll);
			for (int i = 0; i < tmp.size(); i++) {
				if (tmps.count(pos[i])) {
					tmps.erase(pos[i]);
					pp[i] = mp(pos[i], pos[i]);
				}
			}
			for (int i = 0; i < tmp.size(); i++) {
				if (pp[i] == mp(-1ll, -1ll)) {
					pp[i] = mp(pos[i], *tmps.begin());
					tmps.erase(tmps.begin());
				}
			}
			for (int i = 0; i < pos.size(); i++) {
				out[pp[i].first] = pp[(i + 1) % pos.size()].second;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (a[i] == out[i]) k++;
			if (i == out[i]) while (1) {}
		}
		cout << k << '\n';
		for (int i = 1; i <= N; i++) cout << out[i] << ' ';
		cout << '\n';
	}
}