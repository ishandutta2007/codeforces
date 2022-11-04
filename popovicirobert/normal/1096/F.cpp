#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 2e5 + 5;

int p[MAXN + 1], fr1[MAXN + 1], fr2[MAXN + 1];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (1LL * ans * a) % MOD;
        }
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}

struct AIB {
    vector <int> aib;
    int n;
    AIB(int _n) {
        n = _n;
        aib.resize(n + 1);
    }
    inline void update(int pos, int val) {
        for(int i = pos; i <= n; i += lsb(i)) {
            aib[i] += val;
        }
    }
    inline int query(int pos) {
        int ans = 0;
        for(int i = pos; i > 0; i -= lsb(i)) {
            ans += aib[i];
        }
        return ans;
    }
    inline int sum(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        cin >> p[i];
        if(p[i] == -1) {
            cnt++;
        }
        else {
            fr1[p[i]] = fr2[p[i]] = 1;
        }
    }
    for(i = n; i >= 1; i--) {
        fr2[i] += fr2[i + 1];
    }
    for(i = 1; i <= n; i++) {
        fr1[i] += fr1[i - 1];
    }
    int ans = (1LL * (1LL * cnt * (cnt - 1) % MOD) * inv(4)) % MOD;
    AIB aib(n);
    for(i = 1; i <= n; i++) {
        if(p[i] > -1) {
            ans += aib.sum(p[i] + 1, n);
            mod(ans);
            aib.update(p[i], 1);
        }
    }
    int nr = 0;
    for(i = n; i >= 1; i--) {
        nr += (p[i] == -1);
        if(p[i] > -1) {
            int cur = p[i] - fr1[p[i]];
            ans = (ans + 1LL * nr * (1LL * cur * inv(cnt) % MOD)) % MOD;
        }
    }
    nr = 0;
    for(i = 1; i <= n; i++) {
        nr += (p[i] == -1);
        if(p[i] > -1) {
            int cur = n - p[i] + 1 - fr2[p[i]];
            ans = (ans + 1LL * nr * (1LL * cur * inv(cnt) % MOD)) % MOD;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}