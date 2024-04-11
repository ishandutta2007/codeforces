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
const int MAXN = 1e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n", first="tokitsukaze", second="quailty", draw="once again";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll MOD = 998244353;

void solve(){
    //simulate uptil n
    //after n, the max element will stay in the front
    int n, q; cin >> n >> q;
    deque<ll> d; for (int i = 0, a; i < n; i++) cin >> a, d.push_back(a);
    vector<pair<ll, ll>> v(n-1);
    for (int i = 0; i < n-1; i++){
        ll f=d.front(); d.pop_front();
        ll s=d.front(); d.pop_front();
        v[i] = {f, s};
        if (f < s) swap(f, s);
        d.push_front(f); d.push_back(s);
    }
    while (q--){
        ll m; cin >> m; m--;
        if (m < n-1){ cout << v[m].first << ' ' << v[m].second << '\n'; continue; }
        m %= (n-1);
        cout << d.front() << ' ' << d[m+1] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}