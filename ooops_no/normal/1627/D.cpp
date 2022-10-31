#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 1e6 + 10;
vector<int> ok(N);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ok[a[i]] = 1;
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (ok[i]) continue;
        int res = 0;
        for (int j = i; j < N; j += i) {
            if (ok[j]) {
                res = gcd(res, j);
            }
        }
        ans += (res == i);
    }
    cout << ans << endl;
    return 0;
}