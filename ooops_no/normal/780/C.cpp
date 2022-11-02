#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll _in128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 10;
vector<int> g[N];
vector<int> color(N);

void dfs(int v, int p, set<int> st){
    int now = 1;
    for (auto to : g[v]){
        if (to != p){
            while(st.find(now) != st.end()){
                now++;
            }
            color[to] = now;
            st.insert(now);
            set<int> a{color[to], color[v]};
            dfs(to, v, a);
        }
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, (int)g[i].size() + 1);
    }
    color[1] = 1;
    set<int> st{1};
    dfs(1, -1, st);
    cout << ans << endl;
    for (int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
    return 0;
}