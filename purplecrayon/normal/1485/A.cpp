#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
ll calc(ll a, ll b, ll x){
    ll ans=x-b;
    while (a) a /= x, ans++;
    return ans;
}
void solve(){
    ll a, b; cin >> a >> b;
    if (a < b){ cout << 1 << '\n'; return; }
    if (a == b){ cout << 2 << '\n'; return; }

    ll lo=max(1ll, b-1), hi=1e9+1, mid=(lo+hi)/2;
    while (lo < mid && mid < hi){
        if (calc(a, b, mid) > calc(a, b, mid+1)) lo=mid;
        else hi=mid;

        mid=(lo+hi)/2;
    }
    ll ans=1e9+10;
    for (int i = max(max(b, 2ll), hi-100); i < hi+100; i++) ans = min(ans, calc(a, b, i));
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}