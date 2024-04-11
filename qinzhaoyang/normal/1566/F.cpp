#include <stdio.h>
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10, inf = 2e9;

int T, n, m, a[N];
pair <int,int> b[N];
int f[2][2];

int cmp(pair <int,int> A, pair <int,int> B) {
	if (A.second != B.second) return A.second > B.second;
	return A.first > B.first;
}

signed main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort (a + 1, a + n + 1);
		for (int i = 1; i <= m; i++)
			cin >> b[i].first >> b[i].second;
		sort (b + 1, b + m + 1); int j = 1, Min = inf;
		while (j <= m && b[j].first < a[1]) {
			if (b[j].second >= a[1]){
				j++;
				continue;
			}
			Min = min(Min, b[j].second), j++;
		}
		if (Min == inf) f[1][0] = f[1][1] = 0;
		else f[1][0] = a[1] - Min, f[1][1] = (a[1] - Min) * 2;
		for (int i = 1; i < n; i++) {
			f[0][0] = f[1][0], f[0][1] = f[1][1];
			vector <pair <int,int> > t;
			while (j <= m && b[j].first == a[i]) j++;
			while (j <= m && b[j].first < a[i + 1]) {
				if (b[j].second >= a[i + 1]){
					j++;
					continue;
				}
				t.push_back(b[j]), j++;
			}
			if (!t.size()) f[1][0] = f[1][1] = min(f[0][0], f[0][1]);
			else {
				set <pair<int,int> > s;
				for (int j = 0; j < t.size(); j++)
					s.insert(make_pair(t[j].second, j));
				Min = inf;
				for (int j = 0; j < t.size(); j++)
					Min = min(Min, t[j].second);
				f[1][0] = min(f[0][0], f[0][1]) + a[i + 1] - Min;
				f[1][1] = min(f[0][0], f[0][1]) + 2 * (a[i + 1] - Min);
				for (int j = 0; j < t.size(); j++) {
					s.erase(s.find(make_pair(t[j].second, j)));
					auto it = s.begin();
					if (it != s.end()) {
						int tmp = (*it).first;
						f[1][0] = min(f[1][0], min(f[0][1] + t[j].first - a[i] + a[i + 1] - tmp, f[0][0] + 2 * (t[j].first - a[i]) + a[i + 1] - tmp));
						f[1][1] = min(f[1][1], min(f[0][1] + t[j].first - a[i] + 2 * (a[i + 1] - tmp), f[0][0] + 2 * (t[j].first - a[i]) + 2 * (a[i + 1] - tmp)));
					}
				}
				s.clear();
				sort (t.begin(), t.end(), cmp);
				Min = -inf;
				for (int j = 0; j < t.size(); j++)
					Min = max(Min, t[j].first);
				f[1][0] = min(f[1][0], min(f[0][0] + Min - a[i], f[0][1]) + Min - a[i]);
				f[1][1] = min(f[1][1], min(f[0][0] + Min - a[i], f[0][1]) + Min - a[i]);
				for (int j = 0; j < t.size(); j++)
					s.insert(make_pair(-t[j].first, j));
				for (int j = 0; j < t.size(); j++) {
					s.erase(s.find(make_pair(-t[j].first, j)));
					auto it = s.begin();
					if (it != s.end()) {
						int tmp = -(*it).first;
						f[1][0] = min(f[1][0], min(f[0][1] + tmp - a[i] + a[i + 1] - t[j].second, f[0][0] + 2 * (tmp - a[i]) + a[i + 1] - t[j].second));
						f[1][1] = min(f[1][1], min(f[0][1] + tmp - a[i] + 2 * (a[i + 1] - t[j].second), f[0][0] + 2 * (tmp - a[i]) + 2 * (a[i + 1] - t[j].second)));
					}
				}
			}
		}
		Min = -inf;
		while (j <= m && b[j].first == a[n]) j++;
		while (j <= m) Min = max(Min, b[j].first), j++;
		if (Min == -inf) cout << min(f[1][1], f[1][0]) << endl;
		else cout << min(f[1][1] + Min - a[n], f[1][0] + 2 * (Min - a[n])) << endl;
	}
	return 0;
}