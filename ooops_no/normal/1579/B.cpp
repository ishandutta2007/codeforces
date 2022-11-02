#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        vector<pair<int, pair<int, int>>> ans;
        for (int i = 0; i + 1 < n; i++){
            for (int j = i; j < n; j++){
                if (a[j] == b[i]){
                    vector<int> c{a.begin() + i, a.end()};
                    while(a.size() > i){
                        a.pop_back();
                    }
                    int now = 0;
                    for (int k = 0; k < c.size(); k++){
                        if (c[k] == b[i]){
                            if (now > 0) ans.pb({i + 1, {n, now}});
                            for (int f = k; f < c.size(); f++){
                                a.pb(c[f]);
                            }
                            for (int f = 0; f < k; f++){
                                a.pb(c[f]);
                            }
                            break;
                        }
                        now++;
                    }
                    break;
                }
            }
        }
        cout << ans.size() << endl;
        for (auto to : ans){
            cout << to.first << ' ' << to.second.first << ' ' << to.second.second << endl;
        }
    }
    return 0;
}