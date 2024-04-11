#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 5e5 + 3, mod = 998244353;

int n;
int c[max_n];

int dp[max_n * 4][2][2];

void push(int v, int a, int b, int szl, int szr) {
    int l = v * 2;
    int r = v * 2 + 1;
    
    int cnt = 0;
    if (a == 1) {
        //if (a == 0) cnt = b + 1;
        cnt = 9 - b;
    }

    for(int id1 = 0;id1 < 2;id1++) {
        for(int id2 = 0;id2 < 2;id2++) {
            int q = cnt * dp[l][id1][1] * dp[r][1][id2];
            if (szl == 1 && id1 == 1) q = 0;
            if (szr == 1 && id2 == 1) q = 0;
            dp[v][id1][id2] = (dp[l][id1][0] * dp[r][0][id2]) % mod + q % mod;
            dp[v][id1][id2] %= mod;
        }
    }
}


void _set(int v, int l, int r, int id) {
    if (l > id || r < id) return;
    if (l == id && r == id) {
        dp[v][0][1] = 1;
        dp[v][1][0] = 1;
        dp[v][1][1] = 0;
        dp[v][0][0] = c[id] + 1;
        return;
    }
    int m = ((l + r) >> 1);
    _set(v * 2, l, m, id);
    _set(v * 2 + 1, m + 1, r, id);
    push(v, c[m], c[m + 1], m - l + 1, r - m);
}

int _get() {
    return dp[1][0][0];
}

void solve() {
    int m;
    string temp;
    cin >> n >> m >> temp;
    for(int i = 0;i < n;i++) c[i] = temp[i] - '0';

    for(int i = 0;i < n;i++) _set(1, 0, n - 1, i);

    while(m--) {
        int id, d;
        cin >> id >> d;
        id--;
        c[id] = d;
        _set(1, 0, n - 1, id);
        cout << _get() << endl;
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}