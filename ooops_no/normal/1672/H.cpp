#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(51);

const int INF = 1e18;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<vector<int>> cnt(n + 1, vector<int>(2));
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 0; i + 1 < n; i++) {
        cnt[i + 1][0] = cnt[i][0];
        cnt[i + 1][1] = cnt[i][1];
        if (a[i] == a[i + 1]) {
            cnt[i + 1][a[i]]++;
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << max(cnt[r][0] - cnt[l][0], cnt[r][1] - cnt[l][1]) + 1 << endl;
    }
    return 0;
}