#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int MOD = 998244353;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}
 
inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}
 
inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}
 
inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}
 
inline int inv(int u) {
    return power(u, MOD - 2);
}

int n;
pair<int, int> a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, [](pair<int, int> &u, pair<int, int> &v) {
        return u.second < v.second;
    });
    int res = 1;

    for (int i = 1; i <= n; i++) res = mul(res, i);
    // cout << res << endl;

    int last = -1;
    int num = 1;
    int tot = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i].second == last) {
            num++;
            tot = mul(tot, num);
        } else {
            num = 1;
            last = a[i].second; 
        }
    }
    // cout << tot << endl;
    res = sub(res, tot);

    sort(a + 1, a + n + 1, [](pair<int, int> &u, pair<int, int> &v) {
        return u.first < v.first;
    });

    last = -1;
    num = 1;
    tot = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i].first == last) {
            num++;
            tot = mul(tot, num);
        } else {
            num = 1;
            last = a[i].first; 
        }
    }
    // cout << tot << endl;
    res = sub(res, tot);

    sort(a + 1, a + n + 1);

    pair<int, int> lastPair(-1, -1);
    num = 1;
    tot = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == lastPair) {
            num++;
            tot = mul(tot, num);
        } else if (a[i].first >= a[i - 1].first && a[i].second >= a[i - 1].second) {
            num = 1;
            lastPair = a[i]; 
        } else {
            tot = 0;
        }
    }
    // cout << tot << endl;
    res = add(res, tot);

    cout << res << endl;
    return 0;
}