//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)
#define PB push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e5 + 10;
vector<int> vec[maxn];
set<int> ids;
LL sum[maxn];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		vec[--fi].PB(se);
	}
	int mx = 1e6;
	for (int i = 0; i < m; i++) {
		sort(all(vec[i]), greater<int>());
		smin(mx, sz(vec[i]));
	}
	LL ans = 0,
	   cur = 0;
	for (int i = 0; i < m; i++)
		ids.insert(i);
	for (int j = 0; j < maxn; j++) {
		vector<int> bads;
		for (auto i : ids) {
			cur -= sum[i];
			if (j < sz(vec[i]))
				sum[i] += vec[i][j];
			if (j == sz(vec[i]) or sum[i] < 0) {
				sum[i] = 0;
				bads.PB(i);
			}
			cur += sum[i];
		}
		for (auto i : bads)
			ids.erase(i);
		smax(ans, cur);
	}
	cout << ans << endl;
	return 0;
}