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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    vector<int> ans; ans.reserve(n);
    set<int> s; vector<bool> l(n, 1), r(n, 1);
    for (int i = 0; i < n; i++){
        s.insert(a[i]);
        l[i] = (sz(s) == i+1 && (*s.rbegin() == i+1));
    }
    s.clear();
    for (int i = n-1; i >= 0; i--){
        s.insert(a[i]);
        r[i] = (sz(s) == n-i && (*s.rbegin() == n-i));
    }
    for (int i = 0; i < n-1; i++) if (l[i] && r[i+1]) ans.push_back(i+1);
    cout << sz(ans) << '\n';
    for (auto it : ans) if (it && (n-it)) cout << (it) << ' ' << (n-it) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}