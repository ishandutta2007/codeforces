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
    string s, t;
    int x;
    cin >> s
        >> x;
    t = s;
    fill(all(t), '1');
    for (int i = 0; i < sz(s); i++)
        if (s[i] == '0') {
            if (i - x >= 0)
                t[i - x] = '0';
            if (i + x < sz(s))
                t[i + x] = '0';
        }
    for (int i = 0; i < sz(s); i++)
        if (s[i] == '1')
            if (i - x < 0 or t[i - x] != '1')
                if (i + x >= sz(s) or t[i + x] != '1')
                    return cout << -1 << '\n', 0;
    cout << t << '\n';
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