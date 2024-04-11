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
    ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    if (e < f){
        ll nmf = min({b, c, d}); b -= nmf, c -= nmf, d -= nmf;
        ll nme = min(a, d); a -= nme, d -= nme;
        cout << f*nmf + e*nme << '\n';
    } else {
        ll nme = min(a, d); a -= nme, d -= nme;
        ll nmf = min({b, c, d}); b -= nmf, c -= nmf, d -= nmf;
        cout << f*nmf + e*nme << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;// cin >> t; 
    while (t--) solve();
}