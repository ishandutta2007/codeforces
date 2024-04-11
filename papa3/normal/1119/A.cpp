#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int tab[1000010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> tab[i];
    }

    int res=0;
    for (int i=1; i<=n; i++) {
        if (tab[1] != tab[i]) {
            res = max(res, i-1);
        }
        if (tab[n] != tab[i]) {
            res = max(res, n-i);
        }
    }
    cout << res;

    return 0;
}/*

*/