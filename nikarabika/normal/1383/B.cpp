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
    int cnt[30] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int i = 0; i < 30; i++)
            if ((x >> i) & 1)
                cnt[i]++;
    }
    for (int i = 29; i >= 0; i--) if (cnt[i] & 1) {
        int b = n - cnt[i];
        if ((cnt[i] & 2) and (b & 1 ^ 1))
            cout << "LOSE\n";
        else
            cout << "WIN\n";
        return 0;
    }
    cout << "DRAW\n";
    return 0;
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