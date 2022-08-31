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
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;


void solve(){
    int n; ll k; cin >> n >> k;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    sort(a.begin(), a.end());
    vector<ll> ps(n); for (int i = 0; i < n; i++) ps[i] = a[i]+(i?ps[i-1]:0);
    //can i assume one of the endpoints is one of the array endpoints? -> must handle case where the max  is one of the array elements
    //yes
    ll ans=INF;
    for (int i = 0; i < n; i++){
        ll used=a[i]*(i+1)-ps[i], left = k-used;
        if (left < 0) continue;
        
        auto v = [&](ll x) -> bool {
            int idx=lower_bound(a.begin(), a.end(), x)-a.begin();
            ll cost=(ps[n-1]-(idx?ps[idx-1]:0))-(x*(n-idx));
            return cost <= left;
        };
        
        ll lo = a[i]-1, hi = a[n-1]+1, mid=(lo+hi)/2;
        while (lo < mid && mid < hi){
            if (v(mid)) hi = mid;
            else lo = mid;
            mid = (lo+hi)/2;
        }
        ans = min(ans, hi-a[i]);
    }
    for (int i = 0; i < n; i++){
        ll used=(ps[n-1]-(i?ps[i-1]:0))-a[i]*(n-i), left = k-used;
        if (left < 0) continue;
        
        auto v = [&](ll x){
            int idx=upper_bound(a.begin(), a.end(), x)-a.begin()-1;
            ll cost=(idx+1)*x-ps[idx];
            return cost <= left;
        };
        
        ll lo=a[0]-1, hi=a[i]+1, mid=(lo+hi)/2;
        while (lo < mid && mid < hi){
            if (v(mid)) lo = mid;
            else hi = mid;
            mid = (lo+hi)/2;
        }
        ans = min(ans, a[i]-lo);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}