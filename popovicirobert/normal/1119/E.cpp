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

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}


inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}
*/

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    ll sum = 0, ans = 0;
    for(i = 0; i < n; i++) {
        int x;
        cin >> x;
        ll mn = min(1LL * x / 2, sum);
        x -= 2LL * mn, sum -= mn;
        ans += mn + x / 3;
        sum += x % 3;
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}