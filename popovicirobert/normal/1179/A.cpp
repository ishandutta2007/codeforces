#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



/*const int MOD = ;

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
}*/

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



int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    deque <int> deq;
    int mx = 0;
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        deq.push_back(x);
        mx = max(mx, x);
    }

    vector < pair <int, int> > vals(1);
    while(deq.front() != mx) {
        int a = deq.front();
        deq.pop_front();
        int b = deq.front();
        deq.pop_front();
        deq.push_back(min(a, b));
        deq.push_front(max(a, b));
        vals.push_back({a, b});
    }

    vector <int> arr;
    while(deq.size() > 0) {
        arr.push_back(deq.front());
        deq.pop_front();
    }

    while(q > 0) {
        q--;
        ll m;
        cin >> m;
        if(m < vals.size()) {
            cout << vals[m].first << " " << vals[m].second << "\n";
        }
        else {
            cout << mx << " " << arr[(m - vals.size()) % (n - 1) + 1] << "\n";
        }
    }

    return 0;
}