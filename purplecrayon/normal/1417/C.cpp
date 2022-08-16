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
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a ) cin >> it;
    vector<pair<int, int>> diff(n+1, make_pair(-1, 0));
    for (int i = 0; i < n; i++){
        diff[a[i]].second = max(diff[a[i]].second, i-diff[a[i]].first);
        diff[a[i]].first = i;
    }
    vector<int> v(n+1, 1e9);
    for (int i = 1; i <= n; i++) if (diff[i].first != -1) {
        diff[i].second = max(diff[i].second, n-diff[i].first);
        diff[i].first = n;
        // cout << diff[i].second << ' ';
        v[diff[i].second]=min(v[diff[i].second], i);
    }
    for (int i = 1; i <= n; i++){
        v[i] = min(v[i], v[i-1]);
        cout << (v[i]>=1e9?-1:v[i]) << ' ';
    }
    cout << '\n';
    //window must be greater than or equal to it.second
    
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}