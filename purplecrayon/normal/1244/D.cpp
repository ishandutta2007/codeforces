#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n;
ll cost[MAXN][3];
vector<int> adj[MAXN];

void solve(){
    cin >> n;
    for (int j = 0; j < 3; j++) for (int i = 0; i < n; i++) cin >> cost[i][j];
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b),  adj[b].push_back(a);
    }
    if (n == 1){
        int c=0; for (int i = 0; i < 3; i++) if (cost[0][i] < cost[0][c]) c=i;
        cout << cost[0][c] << '\n' << (c+1) << '\n'; return;
    }
    int f=-1;
    for (int i = 0; i < n; i++){
        if (sz(adj[i]) > 2) { cout << "-1\n"; return; }
        if (sz(adj[i]) == 1) f=i;
    }
    int s=adj[f][0]; //cout << f << ' ' << s << '\n';
    auto bld = [&](int c1, int c2){
        vector<int> ret(n, -1), prev; prev.push_back(f), prev.push_back(s);
        ret[f] = c1, ret[s] = c2; //for (auto it : ret) cout << it << ' '; cout << "\n\n";
        for (int i = 2; i < n; i++){
            int p1=prev.back(), p2=prev[i-2];
            int c=adj[p1][p2==adj[p1][0]]; //cout << c << ' ' << p1 << ' ' << p2 << '\n';
            for (int j = 0; j < 3; j++) if (ret[p1] != j && ret[p2] != j) ret[c] = j;
            prev.push_back(c);
        }
        return ret;
    };
    pair<ll, pair<int, int>> ans{INF, {-1, -1}};
    for (int c1 = 0; c1 < 3; c1++) for (int c2 = 0; c2 < 3; c2++) if (c1 != c2) {
        auto cur = bld(c1, c2);
        ll cc=0;
        for (int i = 0; i < n; i++) cc += cost[i][cur[i]];
        ans = min(ans, {cc, {c1, c2}});
    }
    cout << ans.first << '\n';
    auto cur = bld(ans.second.first, ans.second.second);
    for (int i = 0; i < n; i++) cout << (cur[i]+1) << ' ';
    
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}