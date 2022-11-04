#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e5;

int fact[MAXN + 1];
int invfact[MAXN + 1];
int p26[MAXN + 1], p25[MAXN + 1];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
    p26[0] = p25[0] = 1;
    for(int i = 1; i <= n; i++) {
        p26[i] = (1LL * p26[i - 1] * 26) % MOD;
        p25[i] = (1LL * p25[i - 1] * 25) % MOD;
    }
}

inline int comb(int n, int k) {
    return (1LL * fact[n] * ((1LL * invfact[k] * invfact[n - k]) % MOD)) % MOD;
}

string str;

vector < pair <int, int> > lenghts[MAXN + 1];
int now[MAXN + 1];
int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i;
    ios::sync_with_stdio(false);
    cin >> m >> str;
    prec(MAXN);
    int cnt = 0;
    for(i = 1; i <= m; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            cin >> str;
        }
        else {
            cin >> n;
            lenghts[str.size()].push_back({n, ++cnt});
        }
    }
    for(int len = 1; len <= MAXN; len++) {
        if(lenghts[len].size()) {
            int cur = 0;
            for(n = len; n <= MAXN; n++) {
                cur = (1LL * cur * 26) % MOD;
                cur = (cur + 1LL * p25[n - len] * comb(n - 1, len - 1)) % MOD;
                now[n] = cur;
            }
            for(auto it : lenghts[len]) {
                if(it.first >= len)
                    sol[it.second] = now[it.first];
            }
        }
    }
    for(i = 1; i <= cnt; i++) {
        cout << sol[i] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}