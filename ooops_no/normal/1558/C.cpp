#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
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
    int t;
    cin >> t;
    while(t--){
        int n, x = 0;
        cin >> n;
        vector<int> a(n);
        vector<int> ans;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            if (i % 2 != a[i] % 2){
                x = 1;
            }
        }
        if (x){
            cout << -1 << endl;
            continue;
        }
        for (int i = n - 1; i - 1 >= 0; i -= 2){
            for (int f = 0; f < n; f++){
                if (a[f] == i){
                    reverse(a.begin(), a.begin() + f + 1);
                    ans.pb(f + 1);
                    break;
                }
            }
            int need = 0;
            for (int f = 0; f < n; f++){
                if (a[f] == i - 1){
                    reverse(a.begin(), a.begin() + f);
                    ans.pb(f);
                    need = f + 1;
                    break;
                }
            }
            reverse(a.begin(), a.begin() + need + 1);
            ans.pb(need + 1);
            reverse(a.begin(), a.begin() + 3);
            ans.pb(3);
            reverse(a.begin(), a.begin() + i + 1);
            ans.pb(i + 1);
        }
        cout << ans.size() << endl;
        for (auto to : ans){
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}