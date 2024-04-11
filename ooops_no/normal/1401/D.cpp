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
#define int long long

mt19937 rnd(51);

//  ,    

const int N = 1e5 + 10, MOD = 1e9 + 7;
vector<int> g[N];
vector<int> d(N);
vector<int> ans;

void zhfs(int v, int par, int have)
{
    for (auto to : g[v])
    {
        if (to != par)
        {
            int top = have + d[v] - d[to];
            ans.pb((top * d[to]));
            zhfs(to, v, top);
        }
    }
}

void dfs(int v, int par = -1)
{
    d[v] = 1;
    for (auto to : g[v])
    {
        if (to != par)
        {
            dfs(to, v);
            d[v] += d[to];
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ans.clear();
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            d[i] = 0;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        int m;
        cin >> m;
        vector<int> u(m);
        for (int i = 0; i < m; i++)
        {
            cin >> u[i];
        }
        while(u.size() < n - 1)
        {
            u.pb(1);
        }
        sort(u.begin(), u.end());
        while(u.size() > n - 1)
        {
            int k = u[u.size() - 1];
            u.pop_back();
            int v = u[u.size() - 1];
            u.pop_back();
            u.pb((k * v) % MOD);
        }
        dfs(1);
        zhfs(1, -1, 0);
        sort(ans.begin(), ans.end());
        int lool = 0;
        for (int i = n - 2; i > -1; i--)
        {
            lool += ((ans[i] % MOD) * u[i]) % MOD;
            lool %= MOD;
        }
        cout << lool << endl;
    }
    return 0;
}