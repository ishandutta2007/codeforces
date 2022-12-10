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

bool isprime(LL x) {
	if (x <= 1)
		return false;
	for (LL i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

void solve() {
	LL x;
	cin >> x;
	LL sq = sqrt(x) + 1e-9;
	if (sq * sq != x) {
		cout << "NO\n";
		return;
	}
	if (isprime(sq)) {
		cout << "YES\n";
		return;
	}
		cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while (n--)
		solve();
	return 0;
}