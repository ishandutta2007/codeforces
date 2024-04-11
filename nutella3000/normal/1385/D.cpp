#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 2e5 + 1;

int n;
string s;
int pref[max_n][26];

int g(int l, int r, int let) {
    int res = pref[r][let];
    if (l != 0) res -= pref[l - 1][let];
    return res;
}

int f(int l, int r, int let) {
    if (l == r) {
        return let != s[l] - 'a';
    }

    int m = ((l + r) >> 1);
    int left = f(l, m, let + 1) + r - m - g(m + 1, r, let);
    int right = f(m + 1, r, let + 1) + (m - l + 1) - g(l, m, let);
    //if (l == 0 && r == 7) cout << g(m + 1, r, let) << endl;
    return min(left, right);
}

void solve() {
    cin >> n >> s;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < 26;j++) {
            if (j == s[i] - 'a') pref[i][j] = 1;
            else pref[i][j] = 0;
            if (i != 0) pref[i][j] += pref[i - 1][j];
        }
    }

    cout << f(0, n - 1, 0) << endl;
}


signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}