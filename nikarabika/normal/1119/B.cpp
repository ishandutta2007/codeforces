//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, h;
	cin >> n >> h;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int lo = -1, hi = n;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		vector<int> vec;
		for (int i = 0; i <= mid; i++)
			vec.PB(a[i]);
		sort(all(vec), greater<int>());
		LL cur = 0;
		for (int i = 0; i < sz(vec); i+=2)
			cur += vec[i];
		if (cur <= h)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo + 1 << endl;
	return 0;
}