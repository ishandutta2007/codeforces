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
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n;
vector<int> ch[MAXN];
ll a[MAXN];

ar<ll, 3> dfs(int c=0){ //{max, sum, #leaves}
    ar<ll, 3> sub{};
    for (auto nxt : ch[c]){
        auto v = dfs(nxt);
        sub[0] = max(sub[0], v[0]);
        sub[1] += v[1];
        sub[2] += v[2];
    }
    if (!sz(ch[c])) sub[2]++;
    auto ceildiv = [&](ll x, ll y){
        return  (x+y-1)/y;
    };
    ll nmax = ceildiv(max(0ll, a[c]-(sub[0]*sub[2] - sub[1])), sub[2]);
    sub[1] += a[c];
    sub[0] += nmax;
    // cout << c << ' ' << sub[0] << ' ' << sub[1] << ' ' << sub[2] << '\n';
    return sub;
}
void solve(){
    cin >> n;
    for (int i = 1; i < n; i++){
        int p; cin >> p, --p;
        ch[p].push_back(i);
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << (dfs()[0]);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}