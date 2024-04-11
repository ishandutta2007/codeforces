#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

int n, q, st[MAXN], en[MAXN], t[MAXN], tt=0;
vector<int> adj[MAXN];

void dfs(int c=0, int p=-1){
    st[c]=tt++; t[st[c]]=c;
    for (auto nxt : adj[c]) if (nxt != p) dfs(nxt, c);
    en[c]=tt-1;
}
void solve(){
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int p; cin >> p, --p;
        adj[p].push_back(i);
    }
    dfs();
    while (q--){
        int c, k; cin >> c >> k, --c, --k;
        if (st[c]+k>en[c]) cout << "-1\n";
        else cout << (t[st[c]+k]+1) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}