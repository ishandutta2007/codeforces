#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 3);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = 1001;
    a[n + 2] = 1337;
    int last = 0;
    int ans = 0;
    for (int i = 0; i <= n + 2; ++i) {
        if (a[i] - a[last] != i - last) {
            ans = max(ans, i - last - 2);
            last = i;
        }
    }
    cout << ans;
    return 0;
}