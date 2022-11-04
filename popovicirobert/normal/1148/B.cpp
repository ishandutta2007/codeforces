#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

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
}*/

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, ta, tb, k, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> ta >> tb >> k;

    vector <int> a(n), b(m);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(n <= k || m <= k) {
        cout << -1;
        return 0;
    }

    int ans = 0;
    for(i = 0; i <= k; i++) {
        if(a[i] + ta > b[m - (k - i) - 1]) {
            cout << -1;
            return 0;
        }
        int it = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
        ans = max(ans, b[it + (k - i)] + tb);
    }

    cout << ans;

    return 0;
}