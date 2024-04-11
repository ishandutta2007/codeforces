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
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 20, ALP = 24, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e6, MAXB = 20, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, a[MAXN], dp[MAXBB];

ll po(ll b, ll p){
    ll r=1;
    for (; p; p/=2, b=b*b%MOD) if (p&1) r=r*b%MOD;
    return r;
}
ll f(int x){
    //count how many elemenst in a have x as a submask
    //how many elements in a are a submask of x -> SOS dp
    //reverse that???
    return dp[x];
}
ll g(int x){ return __builtin_popcount(x); };
void solve(){
    fsc(n);
    for (int i = 0; i < n; i++) fsc(a[i]);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i) dp[a[i]]++;
<<<<<<< HEAD
    for(int i = MAXB-1; i >= 0; --i) for(int mask = MAXBB-1; mask >= 0; --mask){
=======
    for(int i = 0; i < MAXB; i++) for(int mask = MAXBB-1; mask >= 0; --mask){
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
    	if (mask & (1<<i)) dp[mask^(1<<i)] += dp[mask];
    }
    ll ans=0;
    for (int i = 0; i < MAXBB; i++){
        int mult=((g(i)&1)?-1:1);
        // cout << bitset<MAXB>(i) << ' ' << mult << '\n';
        ans = (ans+mult*po(2, f(i))%MOD+MOD)%MOD;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}