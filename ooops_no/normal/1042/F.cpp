#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 1e6 + 10;
vector<int> g[N];
pair<int,int> ans[N];
int n, k;

void dfs(int v, int p){
    if (g[v].size() == 1){
        ans[v] = {0, 1};
        return;
    }
    multiset<pair<int,int>> st;
    for (auto to : g[v]){
        if (to != p){
            dfs(to, v);
            st.insert({ans[to].first + 1, ans[to].second});
        }
    }
    while(st.size() > 1){
        auto it = st.begin(), itt = st.begin();
        itt++;
        if (it->first + itt->first <= k){
            pair<int,int> p = *it, pp = *itt;
            st.erase(st.find(p));
            st.erase(st.find(pp));
            st.insert({max(p.first, pp.first), p.second + pp.second - 1});
        }
        else break;
    }
    ans[v] = *st.begin();
    st.erase(st.find(*st.begin()));
    for (auto to : st){
        ans[v].second += to.second;
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int s = 0;
    for (int i = 0; i < n; i++){
        if (g[i].size() >= 2){
            s = i;
        }
    }
    dfs(s, -1);
    cout << ans[s].second << endl;
    return 0;
}