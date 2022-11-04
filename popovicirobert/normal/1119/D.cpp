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
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <ll> s(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> s[i];
    }

    sort(next(s.begin()), s.end());

    vector <ll> dif(1);
    for(i = 2; i <= n; i++) {
        dif.push_back(s[i] - s[i - 1]);
    }

    sort(dif.begin(), dif.end());

    vector <ll> sp(n + 1);
    for(i = 1; i <= n; i++) {
        sp[i] = sp[i - 1] + dif[i];
    }

    cin >> q;
    while(q--) {
        ll l, r;
        cin >> l >> r;

        ll len = r - l + 1;
        auto it = upper_bound(dif.begin(), dif.end(), len - 1) - dif.begin() - 1;

        cout << 1LL * n * len - (1LL * it * len - sp[it]) << " ";
    }

    //cin.close();
    //cout.close();
    return 0;
}