#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

/*
const int MOD = ;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}
*/

using namespace std;

vector <ll> x, y;

inline bool ccw(int a, int b, int c) {
    return x[a] * y[b] + x[b] * y[c] + x[c] * y[a] - y[a] * x[b] - y[b] * x[c] - y[c] * x[a] >= 0;
}

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    x.resize(n + 1), y.resize(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        y[i] -= x[i] * x[i];
    }

    vector <int> ord(n);
    iota(ord.begin(), ord.end(), 1);

    sort(ord.begin(), ord.end(), [&](const int &a, const int &b) {

                if(x[a] == x[b]) return y[a] < y[b];
                return x[a] < x[b];

         });

    vector <int> stk(n);
    int sz = -1;

    for(auto it : ord) {
        while(sz >= 1 && ccw(stk[sz - 1], stk[sz], it)) {
            sz--;
        }
        stk[++sz] = it;
    }

    int ans = 0;
    for(i = 0; i < sz; i++) {
        if(x[stk[i]] != x[stk[i + 1]]) {
            ans++;
        }
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}