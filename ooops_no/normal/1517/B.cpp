#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++){
            pair<int,int> p = {0, 0};
            for (int j = 0; j < n; j++){
                for (int k = 0; k < m; k++){
                    if (a[p.first][p.second] > a[j][k]){
                        p.first = j, p.second = k;
                    }
                }
            }
            ans[i][p.first] = a[p.first][p.second];
            a[p.first][p.second] = 2e9;
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (ans[i][j] == -1){
                    for (int k = 0; k < m; k++){
                        if (a[j][k] != 2e9){
                            ans[i][j] = a[j][k];
                            a[j][k] = 2e9;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << ans[j][i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}