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

vector<int> zeroize(string s) {
    s += '0';
    vector<int> poss;
    for (int i = 0; i + 1 < sz(s); i++)
        if (s[i] != s[i + 1])
            poss.PB(i);
    return poss;
}

int solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> svec = zeroize(s);
    vector<int> tvec = zeroize(t);
    reverse(all(tvec));
    cout << sz(svec) + sz(tvec) << '\n';
    for (auto pos : svec)
        cout << pos + 1 << ' ';
    for (auto pos : tvec)
        cout << pos + 1 << ' ';
    cout << '\n';
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