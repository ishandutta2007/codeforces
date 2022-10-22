#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, p[200];
ll ans = 4e18, G, S;
ar<int, 4> e[50000];
vector<ar<int, 3>> ge; // good edges

int find(int i) {
	return i ^ p[i] ? p[i] = find(p[i]) : i;
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)
		return 0;
	if (rand() % 2)
		swap(a, b);
	p[b] = a;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> G >> S;
	for (int i = 0; i < m; ++i)
		cin >> e[i][2] >> e[i][3] >> e[i][0] >> e[i][1], --e[i][2], --e[i][3];
	sort(e, e + m);
	for (int i = 0; i < m; ++i) {
		ge.insert(upper_bound(ge.begin(), ge.end(), ar<int, 3>{e[i][1], -1, -1}), ar<int, 3>{e[i][1], e[i][2], e[i][3]});
		vector<ar<int, 3>> nge;
		iota(p, p + n, 0);
		int cnt = 0, big = 0;
		for (ar<int, 3> x : ge)
			if (merge(x[1], x[2])) {
				nge.push_back(x);
				++cnt, big = max(big, x[0]);
			}
		if (cnt == n - 1)
			ans = min(ans, G * e[i][0] + S * big);
		swap(ge, nge);
	}
	cout << (ans == 4e18 ? -1 : ans);
	return 0;
}