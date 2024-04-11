#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

bool vis[100004] = {};
int res[100004] = {};
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(q); for (int o = 0; o < q; o++) { cin >> a[o]; }
    int cnt = 0;
    for (int i = q - 1; i >= 0; --i) 
    {
        int r = 0;
        if (vis[a[i] + 1]) 
            r++;
        if (vis[a[i] - 1])
            r++;
        res[a[i]] = r; 
        if (!vis[a[i]]) {
            cnt++;
            vis[a[i]] = true;
        }
    }
    int re = 0;
    for (int i = 1; i <= n; ++i) {
        re += res[i];
        re += vis[i];
    }
    cout << 3 * n - 2 - re << "\n";
}