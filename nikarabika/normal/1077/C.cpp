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
	int n;
	cin >> n;
	pii a[n];
	LL sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i].L, a[i].R = i, sum += a[i].L;
	sort(a, a + n);
	vector<int> vec;
	if (a[n - 2].L * 2 == sum - a[n - 1].L)
		vec.PB(a[n - 1].R);
	for (int i = 0; i < n - 1; i++)
		if (a[n - 1].L * 2 == sum - a[i].L)
			vec.PB(a[i].R);
	cout << sz(vec) << '\n';
	for (auto x : vec)
		cout << 1+x << ' ';
	cout << '\n';
	return 0;
}