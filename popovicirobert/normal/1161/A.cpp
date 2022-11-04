#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

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
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    vector <int> x(k + 1), first(n + 1, k + 1);
    for(i = 1; i <= k; i++) {
        cin >> x[i];
        if(first[x[i]] == k + 1) {
            first[x[i]] = i;
        }
    }

    vector <int> last(n + 1);
    for(i = k; i > 0; i--) {
        if(last[x[i]] == 0) {
            last[x[i]] = i;
        }
    }

    ll ans = 0;
    for(i = 1; i <= n; i++) {
        if(first[i] == k + 1) {
            ans++;
        }
        for(int j = i - 1; j <= i + 1; j++) {
            if(j > 0 && j <= n && i != j && last[j] < first[i]) {
                ans++;
            }
        }
        //cerr << i << " " << ans << "\n";
    }

    cout << ans;

    return 0;
}