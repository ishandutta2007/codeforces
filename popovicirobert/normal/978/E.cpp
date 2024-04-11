#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, w;
    ios::sync_with_stdio(false);
    cin >> n >> w;
    ll mn = 1e18, mx = -1e18;
    ll cur = 0;
    for(i = 1; i <= n; i++) {
        cin >> x;
        cur += x;
        mx = max(mx, cur);
        mn = min(mn, cur);
    }
    cout << max(0LL, min(w * 1LL, w - mx) - max(-mn, 0LL) + 1);
    //cin.close();
    //cout.close();
    return 0;
}