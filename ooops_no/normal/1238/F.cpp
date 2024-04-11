#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long
#define ld long double

const int N = 3e5 + 10;
vector<int> g[N];
vector<bool> used(N);
int ans = 1;

int dfs(int v){
    used[v] = 1;
    vector<int> a;
    for (auto to : g[v]){
        if (!used[to]){
            a.pb(dfs(to));
        }
    }
    if (a.size() == 0) return 1;
    sort(a.rbegin(), a.rend());
    if (a.size() >= 2){
        int sum = a[0] + a[1] + a.size() - 1 + (v != 1);
        ans = max(ans, sum);
    }
    int sum = a[0] + a.size();
    ans = max(ans, sum + (v != 1));
    return sum;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            g[i].clear();
            used[i] = 0;
        }
        ans = 1;
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}