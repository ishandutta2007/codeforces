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
        int n, m;
        cin >> n >> m;
        vector<int> x(n);
        vector<vector<int>> s(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            cin >> x[i];
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                char c;
                cin >> c;
                s[i][j] = c - '0';
            }
        }
        int ans = 0;
        vector<int> show(m);
        iota(show.begin(), show.end(), 1);
        for (int i = 0; i < (1 << n); i++){
            int now = 0;
            for (int j = 0; j < n; j++){
                if (i & (1 << j)){
                    now -= x[j];
                }
                else{
                    now += x[j];
                }
            }
            vector<pair<int,int>> all;
            for (int j = 0; j < m; j++){
                int cnt_small = 0, cnt_big = 0;
                for (int k = 0; k < n; k++){
                    if (s[k][j] == 1){
                        if (i & (1 << k)){
                            cnt_big++;
                        }
                        else{
                            cnt_small++;
                        }
                    }
                }
                all.pb({cnt_big - cnt_small, j});
            }
            sort(all.begin(), all.end());
            vector<int> res(m);
            for (int j = 0; j < m; j++){
                res[all[j].second] = j + 1;
                now += all[j].first * (j + 1);
            }
            if (now > ans){
                ans = now;
                show = res;
            }
        }
        for (auto to : show){
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}