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
    int n; cin >> n; if (n <= 3){ cout << 1; return; }
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.end());
    for (auto rem : {0, n-1}){
        vector<ll> v; for (int i = 0; i < n; i++) if (i != rem) v.push_back(a[i].first);
        bool bad=0; 
        for (int i = 1; i < n-1; i++) bad |= (v[i]-v[i-1] != v[1]-v[0]);
        if (!bad){ cout << (a[rem].second+1); return; }
    }
    //now only remove one of the middle elements
    vector<ll> d(n-1); for (int i = 0; i < n-1; i++) d[i] = a[i+1].first-a[i].first;
    vector<ll> l(n-1), r(n-1);
    for (int i = 0; i < n-1; i++){
        l[i] = d[i];
        if (i && l[i-1] != l[i]) l[i] = -1;
    }
    for (int i = n-2; i >= 0; i--){
        r[i] = d[i];
        if (i < n-2 && r[i+1] != r[i]) r[i] = -1;
    }
    for (int i = 0; i < n-2; i++){
        //merge two elements -> try merging i, i+1
        ll v = d[i]+d[i+1];
        if ((!i || l[i-1]==v)&&(i>=n-3||r[i+2]==v)){
            cout << (a[i+1].second+1); return;
        }
    }
    cout << -1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}