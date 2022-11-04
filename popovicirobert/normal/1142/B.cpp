#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

/*inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;

vector < vector <int> > rmq;
vector <char> lg;

inline int get(int l, int r) {
    int bit = lg[r - l + 1];
    return min(rmq[l][bit], rmq[r - (1 << bit) + 1][bit]);
}


int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n, m, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;

    vector <int> p(n + 1), nxt(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for(i = 1; i <= n; i++) {
        if(i == n) {
            nxt[p[i]] = p[1];
        }
        else {
            nxt[p[i]] = p[i + 1];
        }
    }

    vector <int> a(m + 1);
    for(i = 1; i <= m; i++) {
        cin >> a[i];
    }

    vector < vector <int> > dp(m + 1, vector <int>(20));
    vector <int> last(n + 1);

    for(i = m; i >= 1; i--) {
        dp[i][0] = last[nxt[a[i]]];
        last[a[i]] = i;
    }

    for(int bit = 1; bit < 20; bit++) {
        for(i = 1; i <= m; i++) {
            dp[i][bit] = dp[dp[i][bit - 1]][bit - 1];
        }
    }

    rmq.resize(m + 1, vector <int>(20));
    for(i = 1; i <= m; i++) {
        rmq[i][0] = i;
        for(int bit = 0; bit < 20; bit++) {
            if((n - 1) & (1 << bit)) {
                rmq[i][0] = dp[rmq[i][0]][bit];
            }
        }

        if(rmq[i][0] == 0) {
            rmq[i][0] = m + 1;
        }
    }

    for(int bit = 1; bit < 20; bit++) {
        for(i = 1; i + (1 << bit) <= m + 1; i++) {
            rmq[i][bit] = min(rmq[i][bit - 1], rmq[i + (1 << (bit - 1))][bit - 1]);
        }
    }

    lg.resize(m + 1);
    for(i = 2; i <= m; i++) {
        lg[i] = lg[i >> 1] + 1;
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << (get(l, r) <= r);
    }

    //cin.close();
    //cout.close();
    return 0;
}