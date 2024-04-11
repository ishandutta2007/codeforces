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

const int N = 2e5 + 10;
vector<int> g[N];
int ans = 0;

bool dfs(int v, int p){
    int now = 0;
    for (auto to : g[v]){
        if (to != p){
            now += dfs(to, v);
        }
    }
    if (now == 0) return 1;
    ans++;
    return 0;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        ans = 0;
        int val = dfs(0, -1);
        cout << n - 2 * ans + (!val) << endl;
    }
    return 0;
}