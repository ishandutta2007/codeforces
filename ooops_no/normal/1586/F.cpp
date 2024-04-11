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
    vector<pair<int,int>> now;
    for (int i = 0; i < n; i++){
        now.pb({i, i});
    }
    vector<vector<int>> ans(n, vector<int>(n));
    int kek = 1;
    while(now.size() > 1){
        for (int i = 0; i < now.size(); i++){
            for (int j = 0; j < i; j++){
                for (int f = now[i].first; f <= now[i].second; f++){
                    for (int k = now[j].first; k <= now[j].second; k++){
                        ans[k][f] = kek;
                    }
                }
            }
        }
        vector<pair<int,int>> noww;
        for (int i = 0; i < now.size(); i++){
            if (i % k == 0){
                noww.pb(now[i]);
            }
            else{
                noww.back().second = now[i].second;
            }
        }
        now = noww;
        kek++;
    }
    cout << kek - 1 << endl;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            cout << ans[i][j] << ' ';
        }
    }
    cout << endl;
    return 0;
}