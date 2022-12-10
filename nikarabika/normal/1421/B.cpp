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
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    if (s[0][1] == s[1][0]) {
        int cnt = (s[n - 1][n - 2] == s[0][1]) 
            + (s[n - 2][n - 1] == s[0][1]);
        cout << cnt << '\n';
        if (s[n - 1][n - 2] == s[0][1])
            cout << n << ' ' << n - 1 << '\n';
        if (s[n - 2][n - 1] == s[0][1])
            cout << n - 1 << ' ' << n << '\n';
    }
    else if (s[n - 1][n - 2] == s[n - 2][n - 1]) {
        int cnt = (s[n - 1][n - 2] == s[0][1]) 
            + (s[n - 2][n - 1] == s[1][0]);
        cout << cnt << '\n';
        if (s[n - 1][n - 2] == s[0][1])
            cout << 1 << ' ' << 2 << '\n';
        if (s[n - 2][n - 1] == s[1][0])
            cout << 2 << ' ' << 1 << '\n';
    }
    else {
        cout << 2 << '\n';
        if (s[0][1] == '1')
            cout << 1 << ' ' << 2 << '\n';
        else
            cout << 2 << ' ' << 1 << '\n';
        if (s[n - 2][n - 1] == '0')
            cout << n - 1 << ' ' << n << '\n';
        else
            cout << n << ' ' << n - 1 << '\n';
    }
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