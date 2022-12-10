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

int solve() {
    int n, q;
    cin >> n >> q;
    LL even = 0;
    LL odd = -1e18;
    for (int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        LL neven = max(even, odd - x);
        LL nodd = max(odd, even + x);
        even = neven;
        odd = nodd;
    }
    cout << max(even, odd) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}