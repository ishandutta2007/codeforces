#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long

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
        int n, m, s = -1, t = -1;
        cin >> n >> m;
        vector<vector<char>> c(n, vector<char>(m));
        vector<vector<int>> col(n, vector<int>(m));
        vector<vector<bool>> get(n, vector<bool>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> c[i][j];
                if (c[i][j] == 'L'){
                    s = i, t = j;
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (c[i][j] == '#') continue;
                int cnt = 0;
                if (i + 1 < n && c[i + 1][j] != '#') col[i][j]++;
                if (i - 1 >= 0 && c[i - 1][j] != '#') col[i][j]++;
                if (j + 1 < m && c[i][j + 1] != '#') col[i][j]++;
                if (j - 1 >= 0 && c[i][j - 1] != '#') col[i][j]++;
            }
        }
        deque<pair<int,int>> q;
        q.pb({s, t});
        get[s][t] = 1;
        while(q.size() > 0){
            int i = q.front().first, j = q.front().second;
            q.pop_front();
            vector<pair<int,int>> check;
            if (i + 1 < n && c[i + 1][j] != '#') check.pb({i + 1, j});
            if (i - 1 >= 0 && c[i - 1][j] != '#') check.pb({i - 1, j});
            if (j + 1 < m && c[i][j + 1] != '#') check.pb({i, j + 1});
            if (j - 1 >= 0 && c[i][j - 1] != '#') check.pb({i, j - 1});
            for (auto to : check){
                col[to.first][to.second]--;
                if (col[to.first][to.second] <= 1 && !get[to.first][to.second]){
                    get[to.first][to.second] = 1;
                    q.pb({to.first, to.second});
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (c[i][j] != '.') cout << c[i][j];
                else cout << (!get[i][j] ? '.' : '+');
            }
            cout << '\n';
        }
    }
    return 0;
}