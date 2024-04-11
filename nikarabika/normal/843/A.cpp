//sobkskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

const int maxn = 1e5 + 10;
int a[maxn];
bool mark[maxn];
vector<int> vec[maxn],
	all;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], all.PB(a[i]);
	sort(all(all));
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(all(all), a[i]) - all.begin();
	int sz = 0;
	for (int i = 0; i < n; i++) {
		if (mark[i])
			continue;
		int u = i;
		while (!mark[u]) {
			vec[sz].PB(u + 1);
			mark[u] = true;
			u = a[u];
		}
		sz++;
	}
	cout << sz << '\n';
	for (int i = 0; i < sz; i++) {
		cout << sz(vec[i]) << ' ';
		for (auto val : vec[i])
			cout << val << ' ';
		cout << '\n';
	}
	return 0;
}