#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e11 + 7;
 
int n, m, k;
vector<pii> a[4];
vector<int> id(4);
vector<int> res_id(4);


int tim = 0;

bool f() {
	int min_num = k - id[3];
	int cnt = 0;

	for(int i = 1;i <= 2;i++) {
		if (id[i] < min_num) {
			id[i]++;
			tim += a[i][id[i]].first;
			cnt++;
		}
	}

	while(cnt--) {
		vector<int> q(3);
		for(int i = 0;i < 3;i++) q[i] = a[i][id[i]].first;

		for(int i = 1;i < 3;i++) if (id[i] == min_num) q[i] = -10;

		int w = 0;
		for(int i = 0;i < 3;i++) if (q[i] > q[w]) w = i;

		if (id[w] == 0) return false;
		tim -= a[w][id[w]].first;
		id[w]--;
	}

	return true;
}

void solve() {
	cin >> n >> m >> k;
	

	for(int i = 0;i < n;i++) {
		int t, q, w;
		cin >> t >> q >> w;
		a[q * 2 + w].emplace_back(t, i + 1);
	}
	
	for(int i = 0;i < 4;i++) {
		a[i].emplace_back(0, 0);
		for(int j = 0;j < n;j++) a[i].emplace_back(inf, 0);

		sort(a[i].begin(), a[i].end());
	}

	int res = 1e18;

	id[3] = m;
	for(int i = 0;i <= m + 1;i++) tim += a[3][i].first;

	for(int i = m;i >= 0;i--) {
		id[3] = i;
		tim -= a[3][i + 1].first;
		while(id[0] + id[1] + id[2] + id[3] < m) {
			int best = 0;
			for(int i = 0;i < 3;i++) if (a[best][id[best] + 1].first > a[i][id[i] + 1].first) best = i;

			id[best]++;
			tim += a[best][id[best]].first;
		}

		if (!f()) break;
		if (res > tim) {
			res = tim;
			res_id = id;
		}
	}

	if (res >= inf) cout << -1;
	else{
		cout << res << endl;
		for(int i = 0;i < 4;i++) for(int j = 1;j <= res_id[i];j++) cout << a[i][j].second << " "; 
	}
}


signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}