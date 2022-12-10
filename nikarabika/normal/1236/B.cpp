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

const LL Mod = 1e9 + 7;

LL Pow(LL x, LL y) {
	LL an = x,
	   ans = 1;
	while (y) {
		if (y & 1LL)
			ans = ans * an % Mod;
		an = an * an % Mod;
		y >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL n, m;
	cin >> n >> m;
	cout << (Pow(Pow(2, m) - 1, n) + Mod) % Mod << endl;
	return 0;
}