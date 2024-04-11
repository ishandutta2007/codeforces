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
    int n, k; ll p; cin >> n >> p >> k;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    sort(a.begin(), a.end()); int c=0;
    //either take this separately, don't take this, or take this and the previous k
    //observations:
    //if i take the deal, i will never pick smth greater than me again (separately)
    // separate, separate | together, togeter -> wiht a  split
    // each thing on the right side of the split has a cost of mx and a reward of k
    // each thing on the left side of the split has a cost of a[i] and a reward of 1
    // will always take the mins from both sides
    int ans=0, canBuy=n; ll tot=0;
    vector<vector<ll>> poss(k); vector<int> locs(n);
    for (int i = 0; i < n; i++) locs[i] = sz(poss[i%k]), poss[i%k].push_back(a[i]);
    for (int i = 0; i < k; i++){
        for (int j = 1; j < sz(poss[i]); j++) poss[i][j] += poss[i][j-1];
    }
    for (int i = 0; i <= n && tot <= p; i++){ //take the first i separately
        int cur=i;
        if (i+k <= n){
            // int c=locs[i+k-1], idx=(i+k-1)%k; ll used=tot;
            // while (c < sz(poss[idx]) && poss[idx][c]+used <= p) used += poss[idx][c], c++, cur += k;
            int idx=(i+k-1)%k;
            ll lo=locs[i+k-1]-1, hi = sz(poss[idx]), mid=(lo+hi)/2;
            auto v = [&](ll x) -> bool {
                return poss[idx][x]-(locs[i+k-1]?poss[idx][locs[i+k-1]-1]:0)+tot <= p;
            };
            while (lo < mid && mid < hi){
                if (v(mid)) lo=mid;
                else hi=mid;
                mid=(lo+hi)/2;
            }
            cur += k*(lo-locs[i+k-1]+1);
        }
        ans = max(ans, cur);
        if (i < n) tot += a[i];
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t; 
    while (t--) solve();
}