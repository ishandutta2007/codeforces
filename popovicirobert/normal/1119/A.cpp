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
#endif // ONPC
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> first(n + 1), c(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> c[i];
        if(first[c[i]] == 0) {
            first[c[i]] = i;
        }
    }

    vector <int> pref(n + 1, n + 1), suff(n + 2, n + 1);
    for(i = n; i >= 1; i--) {
        if(first[i] == 0) {
            first[i] = n + 1;
        }
        suff[i] = min(suff[i + 1], first[i]);
    }

    for(i = 1; i <= n; i++) {
        pref[i] = min(pref[i - 1], first[i]);
    }

    int ans = 0;
    for(i = 1; i <= n; i++) {
        ans = max(ans, i - min(pref[c[i] - 1], suff[c[i] + 1]));
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}