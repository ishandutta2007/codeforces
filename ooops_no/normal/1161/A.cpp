#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    vector<vector<int>> a(n);
    for (int i = 0; i < k; i++){
        cin >> x[i];
        x[i]--;
        a[x[i]].pb(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        int need = (a[i].size() > 0 ? a[i][0] : k);
        if (need == k) ans++;
        if (i + 1 < n){
            if (lower_bound(a[i + 1].begin(), a[i + 1].end(), need + 1) == a[i + 1].end()){
                ans++;
            }
        }
        if (i - 1 >= 0){
            if (lower_bound(a[i - 1].begin(), a[i - 1].end(), need + 1) == a[i - 1].end()){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}