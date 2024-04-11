#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    //end right before something gets mandatory
    //easy sweep line
    int n; ll t, a, b; cin >> n >> t >> a >> b;
    vector<int> ar(n); vector<ll> ti(n);
    int te=0, th=0;
    for (auto& it : ar) cin >> it, th += it;
    te = n-th;
    for (auto& it : ti) cin >> it;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++){
        mp[ti[i]].push_back(ar[i]);
    }
    ll ph=0, pe=0;
    int ans=0;
    auto qry = [&](int x) -> int {
        ll cur=pe+ph;
        ll req=pe*a+ph*b;
        if (req <= x){
            ll left=x-req;
            if ((te-pe)*a >= left) {
                cur += left/a;
            } else if ((te-pe)*a + (th-ph)*b >= left) cur += (te-pe)+((left-(te-pe)*a)/b);
            else cur += (te-pe)+(th-ph);
            return cur;
        }
        return 0;
    };
    for (auto& x : mp){
        if (x.first != 0){
            ans = max(ans, qry(x.first-1));
        }
        for (auto nxt : x.second){
            if (nxt) ph++;
            else pe++;
        }
    }
    ans = max(ans, qry(t));
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t; 
    while (t--) solve();
}