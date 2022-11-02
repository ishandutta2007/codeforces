#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2010;
vector<vector<pair<char, int>>> mn(N, vector<pair<char, int>>(N));

void upd(int i, int j, char c, int k){
    if (c < mn[i][j].first){
        mn[i][j] = {c, k};
    }
    else if (c == mn[i][j].first){
        if (k < mn[i][j].second){
            mn[i][j].second = k;
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            mn[i][j] = {'z', 1e18};
        }
    }
    vector<vector<char>> v(n, vector<char>(n));
    vector<vector<pair<int,int>>> p(2 * n - 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
            p[i + j].pb({i, j});
        }
    }
    string ans = "";
    vector<pair<int, int>> now;
    now.pb({0, 0});
    mn[0][0] = {v[0][0], 0};
    if (k > 0){
        upd(0, 0, 'a', 1);
    }
    ans = mn[0][0].first;
    for (int i = 1; i < 2 * n - 1; i++){
        set<pair<int,int>> st;
        for (auto to : now){
            if (1 + to.first < n){
                upd(to.first + 1, to.second, v[to.first + 1][to.second], mn[to.first][to.second].second);
                if (mn[to.first][to.second].second != k){
                    upd(to.first + 1, to.second, 'a', mn[to.first][to.second].second + 1);
                }
                st.insert({to.first + 1, to.second});
            }
            if (1 + to.second < n){
                upd(to.first, to.second + 1, v[to.first][to.second + 1], mn[to.first][to.second].second);
                if (mn[to.first][to.second].second != k){
                    upd(to.first, to.second + 1, 'a', mn[to.first][to.second].second + 1);
                }
                st.insert({to.first, to.second + 1});
            }
        }
        char mnn = 'z';
        for (auto to : st){
            mnn = min(mnn, mn[to.first][to.second].first);
        }
        now.clear();
        ans += mnn;
        for (auto to : st){
            if (mn[to.first][to.second].first == mnn){
                now.pb({to.first, to.second});
            }
        }
    }
    cout << ans << endl;
    return 0;
}