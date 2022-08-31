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
const int MAXN = 18, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

int n;
ld a[MAXN][MAXN], dp[1<<MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    dp[(1<<n)-1]=1;
    for (int i = (1<<n)-1; i > 0; i--) {
        ld cnt=__builtin_popcount(i);
        ld nm=((ld)1)/(((ld)cnt*(cnt-1))/((ld)2));
        for (int j = 0; j < n; j++) if (i&(1<<j)) for (int k = j+1; k < n; k++) if (i&(1<<k)){
            dp[i^(1<<j)] += dp[i]*a[k][j]*nm;
            dp[i^(1<<k)] += dp[i]*a[j][k]*nm;
        }
    }
    cout << fixed << setprecision(8);
    for (int i = 0; i < n; i++) cout << dp[1<<i] << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}