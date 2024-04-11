#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb emplace_back
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        int n, bal = 0, ans = 0;
        cin >> n;
        vector<int> a(n), b(n), m(n), cola(n), colb(n);
        map<int, vector<int>> all;
        for (int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> m[i];
            all[a[i] + b[i] - m[i]].pb(i);
        }
        for (auto to : all){
            sort(to.second.begin(), to.second.end(), [&](int i, int j) {return a[i] - max(0ll, m[i] - b[i]) < a[j] - max(0ll, m[j] - b[j]);});
            int last = 1e18;
            for (auto t : to.second){
                if (a[t] - last < 0 || m[t] - (a[t] - last) < 0 || m[t] - (a[t] - last) > b[t]) {
                    last = a[t] - max(0ll, m[t] - b[t]);
                    ans++;
                }
                cola[t] = a[t] - last, colb[t] = m[t] - cola[t];
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++){
            cout << cola[i] << ' ' << colb[i] << endl;
        }
    }
    return 0;
}