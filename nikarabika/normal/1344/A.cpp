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
    int n;
    cin >> n;
    int a[n];
    bool mark[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += i;
    }
    for (int i = 0; i < n; i++) {
        int x = a[i] % n;
        if (x < 0)
            x += n;
        if (!mark[x])
            mark[x] = true;
        else
            return cout << "NO\n", 0;
    }
    return cout << "YES\n", 0;
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