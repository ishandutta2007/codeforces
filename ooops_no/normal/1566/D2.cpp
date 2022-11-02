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

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> sum(n, vector<int>(m));
        vector<vector<int>> bst(n, vector<int>(m));
        vector<int> b;
        map<int, vector<pair<int, pair<int,int>>>> mp;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                b.pb(a[i][j]);
            }
        }
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        for (auto to : b){
            if (mp[to].size() == 0 || mp[to].back().first != i){
                mp[to].pb({i, {j, j}});
            }
            else{
                mp[to].back().second.second++;
            }
            j++;
            if (j >= m) {
                j -= m;
                i++;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                bst[i][j] = m - j - 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                pair<int,int> p = {-1, -1};
                vector<pair<int, pair<int,int>>> b;
                for (auto to : mp[a[i][j]]){
                    if (to.second.first > to.second.second) continue;
                    b.pb(to);
                    if (p.first == -1 || bst[to.first][to.second.second] < bst[p.first][p.second]){
                        p = {to.first, to.second.second};
                    }
                }
                ans += sum[p.first][p.second];
                for (int jj = p.second; jj < m; jj++){
                    sum[p.first][jj]++;
                }
                for (int jj = 0; jj < p.second; jj++){
                    bst[p.first][jj]--;
                }
                for (int i = 0; i < b.size(); i++){
                    if (b[i].first == p.first && b[i].second.second == p.second){
                        b[i].second.second--;
                    }
                }
                mp[a[i][j]] = b;
            }
        }
        cout << ans << endl;
    }
    return 0;
}