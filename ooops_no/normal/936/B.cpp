#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
#include<unordered_set>

using namespace std;

/*

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;

*/
/*

st.find_by_order();
st.order_of_key();

*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double

mt19937 rnd(51);

//  ,    

const int N = 1e5 + 10;
vector<int> color(N);
vector<int> g[N]    ;
vector<int> cnt(N);
int used[N][2];
int par[N][2];
bool x = 0;

void dfs(int v)
{
    color[v] = 1;
    for (auto to : g[v])
    {
        if (color[to] == 0)
        {
            dfs(to);
        }
        else if (color[to] == 1)
        {
            x = 1;
        }
    }
    color[v] = 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int a;
            cin >> a;
            g[i].pb(a);
        }
    }
    int s;
    cin >> s;
    dfs(s);
    deque<pair<int,int>> st;
    vector<int> check(n + 1);
    st.push_back({0, s});
    used[s][0] = 1;
    while(!st.empty())
    {
        auto to = st.front();
        st.pop_front();
        int v = to.second;
        int now = (to.first + 1) % 2;
        for (auto to : g[v])
        {
            if (!used[to][now]){
                used[to][now] = 1;
                st.push_back({now, to});
                par[to][now] = v;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 0 && used[i][1])
        {
            vector<int> ans;
            int now = 1;
            while(par[i][now] != 0)
            {
                ans.pb(i);
                i = par[i][now];
                now = (now + 1) % 2;
            }
            ans.pb(s);
            cout << "Win" << endl;
            for (int i = ans.size() - 1; i > -1; i--)
            {
                cout << ans[i] << " ";
            }
            return 0;
        }
    }
    if (x)
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << "Lose" << endl;
    }
    return 0;
}