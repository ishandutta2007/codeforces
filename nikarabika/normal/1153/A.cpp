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
	int n, t;
	cin >> n >> t;
	int mnval = 1e9,
		ansid = -1;
	for (int i = 0; i < n; i++) {
		int s, d;
		int cur = 0;
		cin >> s >> d;
		if (s >= t)
			cur = s;
		else {
			int nt = t - s;
			cur = nt + (d - (nt % d)) % d;
			cur += s;
		}
		if (cur < mnval)
			mnval = cur, ansid = i;
	}
	cout << ansid  + 1 << endl;
	return 0;
}