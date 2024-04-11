#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

inline ll get(int pos, int n) {
    return 1LL * (pos - 1) * pos / 2 + 1LL * (n - pos) * (n - pos + 1) / 2;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    ll sum = 0;
    for(i = 1; i <= m; i++) {
        ll x, d;
        cin >> x >> d;
        sum += max(d * get(1, n), d * get((n + 1) / 2, n)) + x * n;
    }
    cout << fixed << setprecision(20) << 1.0 * sum / n;
    //cin.close();
    //cout.close();
    return 0;
}