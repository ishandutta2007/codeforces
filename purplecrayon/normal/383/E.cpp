#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e4+10, MAXQ = 3e5+10, MAXL = 20, ALP = 24, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, a[MAXN];
ll dp[1<<MAXB];
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++){
        string s; cin >> s; a[i] = 0;
        for (auto c : s) a[i] |= 1ll<<(c-'a');
        dp[a[i]]++;
    }
    for(int i = 0; i < MAXB; ++i) for(int mask = 0; mask < MAXBB; ++mask){
    	if(mask & (1<<i)) dp[mask] += dp[mask^(1<<i)];
    }
    //dp[mask] -> number of ways to only pick stuff from mask
    ll ans=0;
    for (int i = 0; i < MAXBB; i++){
        int ni = (~i)&(MAXBB-1);
        ll cans = n-dp[ni];
        ans ^= cans*cans;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}