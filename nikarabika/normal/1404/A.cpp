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
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < k; i++) {
        char prev = 0;
        for (int j = i; j < n; j += k) {
            if (s[j] != '?') {
                if (!prev)
                    prev = s[j];
                else if (s[j] != prev)
                    return cout << "NO\n", 0;
            }
        }
        if (prev)
            for (int j = i; j < n; j += k)
                s[j] = prev;
    }
    int cnt[2] = {0};
    for (int i = 0; i < k; i++)
        if (s[i] != '?')
            cnt[s[i] - '0']++;
    if (cnt[0] <= k / 2 and cnt[1] <= k / 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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