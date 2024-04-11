#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> ans;
vector<pair<int,int>> edge;
vector<bool> used(N);

void dfs(int v){
    used[v] = 1;
    ans.pb(v);
    for (auto to : g[v]){
        if (!used[to]){
            edge.pb({to, v});
            dfs(to);
        }
    }
}

int ask(vector<int> a){
    cout << "? " << a.size() << " ";
    for (auto to : a) cout << to + 1 << " ";
    cout << endl;
    int mx;
    cin >> mx;
    return mx;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> qu(n);
    iota(qu.begin(), qu.end(), 0);
    int mx = ask(qu);
    dfs(0);
    int l = 0, r = n - 1;
    while(r - l > 1){
        int mid = (r + l) / 2;
        vector<int> all;
        for (int i = 0; i <= mid; i++) all.pb(ans[i]);
        int now_mx = ask(all);
        if (now_mx == mx){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << "! " << edge[r - 1].first + 1 << ' ' << edge[r - 1].second + 1 << endl;
    return 0;
}