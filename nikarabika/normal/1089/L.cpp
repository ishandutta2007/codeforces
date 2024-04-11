//sobskdrbhvk...
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define smin(x, y) x = min(x, y)
#define PB push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e5 + 10;
vector<int> vec[maxn];
int a[maxn],
	b[maxn];

bool cmp(int i, int j) {
	return b[i] < b[j];
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i], a[i]--;
		vec[a[i]].PB(i);
	}
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		sort(all(vec[i]), cmp);
		for (int j = 0; j + 1 < sz(vec[i]); j++)
			vec[k].PB(vec[i][j]);
		if (sz(vec[i]) == 0)
			cnt++;
	}
	sort(all(vec[k]), cmp);
	LL ans = 0;
	for (int i = 0; i < cnt; i++)
		ans += b[vec[k][i]];
	cout << ans << endl;
	return 0;
}