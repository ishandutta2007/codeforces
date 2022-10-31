#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n), ans(n);
        for (int i = 0; i < n; i++){
            cin >> p[i];
            p[i]--;
        }
        string s;
        cin >> s;
        vector<pair<int,int>> a, b;
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                a.pb({p[i], i});
            }
            else{
                b.pb({p[i], i});
            }
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        int now = n;
        for (int i = 0; i < a.size(); i++){
            ans[a[i].second] = now--;
        }
        for (int i = 0; i < b.size(); i++){
            ans[b[i].second] = now--;
        }
        for (auto to : ans) cout << to << ' ';
        cout << endl;
    }
    return 0;
}