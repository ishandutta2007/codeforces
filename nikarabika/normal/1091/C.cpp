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

LL get(LL val, LL len) {
	return val / len * (1 + val - len + 1) / 2;
}

vector<LL> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL n;
	cin >> n;
	for (int i = 1; i * i <= n; i++) {
		if (n % i)
			continue;
		ans.PB(get(n, i));
		if (i * i != n)
			ans.PB(get(n, n / i));
	}
	sort(all(ans));
	for (auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}