#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; ll sx, sy; cin >> n >> sx >> sy;
    vector<pair<ll, ll>> v(n); for (auto& it : v) cin >> it.first >> it.second;
    auto dist = [&](pair<ll, ll> a, pair<ll, ll> b) -> ll {
        return abs(a.first-b.first)+abs(a.second-b.second);
    };
    auto getAns = [&](pair<ll, ll> pos) -> int {
        int ret=0;
        for (auto it : v){
            ret += (dist(it, pos)+dist(pos, {sx, sy})==dist(it, {sx, sy}));
        }
        return ret;
    };
    pair<int, pair<ll, ll>> ans{-1, {-1, -1}};
    for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) if (i||j) {
        pair<ll, ll> pos{sx+i, sy+j};
        ans = max(ans, {getAns(pos), pos});
    }
    cout << ans.first << "\n" << ans.second.first << ' ' << ans.second.second;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;// cin >> t; 
    while (t--) solve();
}