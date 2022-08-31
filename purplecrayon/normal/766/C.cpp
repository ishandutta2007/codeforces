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
const int MAXN = 1e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e6, MAXB = 20, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void add(ll& x, ll y){
    x += y; if (x >= MOD) x -= MOD;
}

int n, a[ALP];
ll dp[MAXN];
string s;
void one(){ //num ways
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++){
        int mn=n;
        for (int j = i; j >= 0; j--){
            mn = min(mn, a[s[j]-'a']); if (mn < i-j+1) break;
            add(dp[i], (j?dp[j-1]:1));
        }
    }
    cout << dp[n-1] << '\n';
}
void two(){ //max len of a substring
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++){
        int mn=n;
        for (int j = i; j >= 0; j--){
            mn = min(mn, a[s[j]-'a']); if (mn < i-j+1) break;
            dp[i] = max(dp[i], max((ll)i-j+1, (j?dp[j-1]:0)));
        }
    }
    cout << dp[n-1] << '\n';
}
void three(){ //min num of substrigns
    for (int i = 0; i < n; i++){
        dp[i] = 1e9;
        int mn=n;
        for (int j = i; j >= 0; j--){
            mn = min(mn, a[s[j]-'a']); if (mn < i-j+1) break;
            dp[i] = min(dp[i], (ll)1+(j?dp[j-1]:0));
        }
    }
    cout << dp[n-1] << '\n';
}
void solve(){
    cin >> n >> s;
    for (int i = 0; i < ALP; i++) cin >> a[i];
    one(); two(); three();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}