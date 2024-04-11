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

LL f(LL x) {
	x++;
	while (x % 10 == 0)
		x /= 10;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	map<LL, bool> mark;
	LL x;
	cin >> x;
	int ans = 0;
	while (!mark[x]) {
		ans++;
		mark[x] = true;
		x = f(x);
	}
	cout << ans << endl;
	return 0;
}