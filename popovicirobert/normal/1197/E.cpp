#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


const int MOD = (int) 1e9 + 7;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

/*int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}*/

using namespace std;

const int MAXN = (int) 2e5 + 5;

struct Doll {
    int out, in;
    bool operator <(const Doll &other) const {
        //if(in == other.in) return out < other.out;
        return in > other.in;
    }
}arr[MAXN + 1];

inline pair <int, ll> combine(pair <int, ll> a, pair <int, ll> b) {
    pair <int, ll> ans = a;
    if(ans.second > b.second) {
        ans = b;
    }
    else if(ans.second == b.second) {
        add(ans.first, b.first);
    }
    return ans;
}


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 1; i <= n; i++) {
        cin >> arr[i].out >> arr[i].in;
    }

    sort(arr + 1, arr + n + 1);

    /*for(i = 1; i <= n; i++) {
        cerr << arr[i].out << " " << arr[i].in << "\n";
    }*/

    vector <int> suff(n + 2, 2 * MOD);
    for(i = n; i >= 1; i--) {
        suff[i] = min(suff[i + 1], arr[i].out);
    }

    vector < pair <int, ll> > dp(n + 1, {0, 2 * MOD}), sp(n + 1, {0, 2 * MOD});
    pair <int, ll> ans = {0, 2 * MOD};

    //cerr << "\n";

    for(i = 1; i <= n; i++) {
        int res = 0;
        for(int step = 1 << 17; step; step >>= 1) {
            if(res + step <= n && arr[res + step].in >= arr[i].out) {
                res += step;
            }
        }

        if(res == 0) {
            dp[i] = {1, arr[i].in};
        }
        else {
            dp[i] = sp[res];
            dp[i].second += arr[i].in - arr[i].out;
        }

        //cerr << dp[i].first << " " << dp[i].second << "\n";

        sp[i] = combine(sp[i - 1], dp[i]);

        if(suff[i + 1] > arr[i].in) {
            ans = combine(ans, dp[i]);
        }
    }

    cout << ans.first;

    return 0;
}