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
#include<cassert>
#include <iomanip>

using namespace std;

/*

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<pair<int, pair<int,int>>, null_type, less<pair<int, pair<int,int>>>, rb_tree_tag, tree_order_statistics_node_update> st;


*/

/*

st.find_by_order();
st.order_of_key();

*/

#define pb push_back
#define ld double
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
set<int> g[N];
set<int> need;

void dfs(int v){
    need.erase(v);
    vector<int> go;
    for (auto to : need){
        if (g[v].find(to) == g[v].end()){
            go.pb(to);
        }
    }
    for (auto to : go) need.erase(to);
    for (auto to : go){
        dfs(to);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        need.insert(i);
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (need.find(i) != need.end()){
            ans++;
            dfs(i);
        }
    }
    cout << ans - 1 << endl;
    return 0;
}