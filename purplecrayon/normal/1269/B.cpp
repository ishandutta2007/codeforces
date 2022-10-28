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
    //adding 1 rotates everything to the right by one
    int n; ll m; cin >> n >> m;
    map<ll, int> c1, c2;
    for (int i = 0, a; i < n; i++) cin >> a, c1[a]++;
    for (int i = 0, a; i < n; i++) cin >> a, c2[a]++;
    assert(sz(c1)==sz(c2));
    ll ans=(c1==c2?0:1e18);
    for (auto it : c2){
        //shift c1 by this
        ll shift=(it.first-(c1.begin()->first)+m)%m;
        map<ll, int> nmp;
        for (auto it2 : c1) nmp[(it2.first+shift)%m]+=it2.second;
        // if (shift == 1){
            // for (auto it2 : nmp) cout << it2.first << ' ' << it2.second << '\n';
        // }
        if (nmp==c2) ans = min(ans, shift);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;// cin >> t; 
    while (t--) solve();
}