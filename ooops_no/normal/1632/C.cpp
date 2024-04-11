#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

int solve(int a, int b) {
    int res = b - a;
    for (int j = b; j <= 2 * b; j++) {
        int val = j;
        for (int k = 20; k >= 0; k--) {
            if (val & (1 << k)) {
                if (val - (1 << k) >= a) {
                    val -= (1 << k);
                }
            }
        }
        if (j != a) res = min(res, val - a + j - b + 1);
        else res = min(res, val - a + j - b);
    }
    return res;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}