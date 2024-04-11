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

bool together(pair<int,int> a, pair<int,int> b){
    return (abs(a.first - b.first) + abs(a.second - b.second)) <= 1;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(4, vector<int>(n));
    vector<pair<int,int>> pos(k), need_pos(k);
    vector<int> cnt(k);
    vector<bool> used(k);
    vector<vector<bool>> have(4, vector<bool>(n));
    vector<vector<vector<bool>>> was(k, vector<vector<bool>>(4, vector<bool>(n)));
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
            if ((i == 0 || i == 3) && v[i][j] > 0){
                need_pos[v[i][j] - 1] = {i, j};
            }
            if ((i == 1 || i == 2) && v[i][j] > 0){
                pos[v[i][j] - 1] = {i, j};
                have[i][j] = 1;
            }
        }
    }
    vector<pair<int, pair<int,int>>> ans;
    while(1){
        for (int i = 0; i < k; i++){
            if (!used[i] && together(need_pos[i], pos[i])){
                ans.pb({i + 1, need_pos[i]});
                have[pos[i].first][pos[i].second] = 0;
                used[i] = 1;
            }
        }
        bool x = 0;
        for (int i = 0; i < k; i++){
            if (used[i]) continue;
            if (pos[i].first == 1){
                if (pos[i].second + 1 < n && !have[1][pos[i].second + 1] && !was[i][1][pos[i].second + 1]){
                    have[pos[i].first][pos[i].second] = 0;
                    pos[i].second++;
                    was[i][pos[i].first][pos[i].second] = 1;
                    have[pos[i].first][pos[i].second] = 1;
                    ans.pb({i + 1, pos[i]});
                    x = 1;
                    break;
                }
                if (pos[i].second + 1 == n && !have[2][pos[i].second] && !was[i][2][pos[i].second]){
                    have[pos[i].first][pos[i].second] = 0;
                    pos[i].first++;
                    was[i][pos[i].first][pos[i].second] = 1;
                    have[pos[i].first][pos[i].second] = 1;
                    ans.pb({i + 1, pos[i]});
                    x = 1;
                    break;
                }
            }
            else{
                if (pos[i].second - 1 >= 0 && !have[2][pos[i].second - 1] && !was[i][2][pos[i].second - 1]){
                    have[pos[i].first][pos[i].second] = 0;
                    pos[i].second--;
                    was[i][pos[i].first][pos[i].second] = 1;
                    have[pos[i].first][pos[i].second] = 1;
                    ans.pb({i + 1, pos[i]});
                    x = 1;
                    break;
                }
                if (pos[i].second == 0 && !have[1][pos[i].second] && !was[i][1][pos[i].second]){
                    have[pos[i].first][pos[i].second] = 0;
                    pos[i].first--;
                    was[i][pos[i].first][pos[i].second] = 1;
                    have[pos[i].first][pos[i].second] = 1;
                    ans.pb({i + 1, pos[i]});
                    x = 1;
                    break;
                }
            }
        }
        if (!x) break;
    }
    if (*min_element(used.begin(), used.end()) == 0){
        cout << -1 << endl;
    }
    else{
        cout << ans.size() << endl;
        for (auto to : ans){
            cout << to.first << ' ' << to.second.first + 1 << ' ' << to.second.second + 1 << endl;
        }
    }
    return 0;
}