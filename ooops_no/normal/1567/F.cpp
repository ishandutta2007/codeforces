#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

int n, m;
vector<pair<int,int>> ddd{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int,int>> dd{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool check(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c[i][j] == 'X'){
                int cnt = 0;
                for (auto to : ddd){
                    cnt += c[i + to.first][j + to.second] == '.';
                }
                if (cnt % 2 == 1){
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    vector<vector<bool>> used(n, vector<bool>(m));
    vector<vector<int>> d(n, vector<int>(m, 1e18));
    vector<vector<int>> ans(n, vector<int>(m));
    deque<pair<int,int>> q{{0, 0}};
    d[0][0] = 0;
    while(q.size() > 0){
        int i = q.front().first, j = q.front().second;
        q.pop_front();
        if (used[i][j]) continue;
        used[i][j] = 1;
        for (auto to : dd){
            if (check(i + to.first, j + to.second) && c[i + to.first][j + to.second] == '.'){
                int nw = d[i][j];
                if (d[i + to.first][j + to.second] > nw){
                    q.push_front({i + to.first, j + to.second});
                    d[i + to.first][j + to.second] = nw;
                }
            }
        }
        for (auto to : ddd){
            if (check(i + to.first, j + to.second) && c[i + to.first][j + to.second] != '.'){
                int nw = d[i][j] + 1;
                if (d[i + to.first][j + to.second] > nw){
                    q.pb({i + to.first, j + to.second});
                    d[i + to.first][j + to.second] = nw;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c[i][j] == 'X') continue;
            ans[i][j] = ((j & 1) ^ (d[i][j] & 1) ? 4 : 1);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c[i][j] == 'X'){
                for (auto to : ddd){
                    ans[i][j] += (c[to.first + i][to.second + j] == '.') * ans[i + to.first][j + to.second];
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}