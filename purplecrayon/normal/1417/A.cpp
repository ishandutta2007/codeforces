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

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& it : a ) cin >> it;
    int mn = min_element(a.begin(), a.end())-a.begin();
    int ans=0, nmn = 1e9;
    for (int i = 0; i < n; i++) if (i != mn) {
        ans += (k-a[i])/(a[mn]);
        a[i] += a[mn]*((k-a[i])/(a[mn]));
        nmn = min(nmn,a[i]);
    }
    ans += (k-a[mn])/nmn;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}