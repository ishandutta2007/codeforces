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
    vector<ll> a(n); for (auto& it : a) cin >> it;
    //for them to be greater -> each bit
    //1, 1 somewhere in this before a 1, 0 ({1,1} is the only comb where and beats xor) -> (1, 1) before the (1, 0) -> can only pair numbers with the same highest one bit
    ll cnt[50]={};
    for (int i = 0; i < n; i++){
        ll c=a[i], nm=0;
        while (c) nm++, c /= 2;
        cnt[nm]++;
    }
    ll ans=0;
    for (int i = 0; i < 40; i++) ans += (cnt[i]*(cnt[i]-1))/2;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}