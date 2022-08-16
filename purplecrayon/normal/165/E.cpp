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
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 22;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, a[MAXN], dp[1<<MAXB];
void solve(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) cin >> a[i], dp[a[i]]=a[i];
    for(int i = 0; i < MAXB; ++i) for(int mask = 0; mask < (1<<MAXB); ++mask){
    	if(mask & (1<<i)) dp[mask] = max(dp[mask], dp[mask^(1<<i)]);
    }
    for (int i = 0; i < n; i++){
        ui c=a[i], nc=(~c)&((1<<MAXB)-1);
        cout << dp[nc] << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}