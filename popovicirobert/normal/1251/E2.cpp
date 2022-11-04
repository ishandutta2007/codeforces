#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



#if 0
const int MOD = ;

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

inline int inv(int x) {
    return lgput(x, MOD - 2);
}
#endif

#if 0
int fact[], invfact[];

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
}
#endif

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> n;

        vector < vector <int> > vals(n + 1);
        vector <int> need(n + 1);

        for(i = 1; i <= n; i++) {
            int m, p;
            cin >> m >> p;
            vals[m].push_back(p);
        }
        int cnt = 0;
        for(i = 0; i <= n; i++) {
            need[i] = max(0, i - cnt);
            cnt += vals[i].size();
        }

        priority_queue <int> pq;
        ll ans = 0;
        int taken = 0;
        for(i = n; i >= 1; i--) {
            for(auto it : vals[i]) {
                pq.push(-it);
            }
            while(need[i] - taken > 0) {
                ans -= pq.top();
                pq.pop();
                taken++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}