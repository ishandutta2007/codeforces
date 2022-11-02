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

#define pb emplace_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g(N), p(N), t(N);

bool cmp(int i, int j){
    return p[i] < p[j];
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w, h;
    cin >> n >> w >> h;
    vector<pair<int,int>> ans(n, {-1, -1});
    map<int, vector<int>> d[2];
    set<int> st;
    for (int i = 0; i < n; i++){
        cin >> g[i] >> p[i] >> t[i];
        g[i]--;
        st.insert(p[i] - t[i]);
        d[g[i]][p[i] - t[i]].pb(i);
    }
    for (auto to : st){
        int j = 0;
        sort(d[0][to].begin(), d[0][to].end(), cmp);
        sort(d[1][to].begin(), d[1][to].end(), cmp);
        int mx = (d[0][to].size()) - 1;
        for (int i = (int)(d[0][to].size()) - 1; i >= 0; i--){
            if (j < d[1][to].size()){
                ans[d[0][to][i]] = {w, p[d[1][to][j]]};
                j++;
            }
            else ans[d[0][to][i]] = {p[d[0][to][mx--]], h};
        }
        j = 0;
        mx = d[1][to].size() - 1;
        for (int i = (int)(d[1][to].size()) - 1; i >= 0; i--){
            if (j < d[0][to].size()){
                ans[d[1][to][i]] = {p[d[0][to][j]], h};
                j++;
            }
            else ans[d[1][to][i]] = {w, p[d[1][to][mx--]]};
        }
    }
    for (auto to : ans){
        cout << to.first << ' ' << to.second << endl;
    }
    return 0;
}