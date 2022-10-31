#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int INF = 1e18;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mx = INF, j = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt = (n + i - 1) / i;
        if (cnt + i < mx) {
            mx = cnt + i;
            j = i;
        }
    }
    int now = n;
    while (now >= j) {
        for (int i = now - j + 1; i <= now; i++) {
            cout << i << ' ';
        }
        now -= j;
    }
    for (int i = 1; i <= now; i++) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}