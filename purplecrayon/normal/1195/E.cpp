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
const int MAXN = 3e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll MOD = 998244353;

vector<int> r;
void getMins(vector<ll>& v, int k){
    deque<int> q; int n=v.size();
    r.resize(n-k+1);
    for (int i = 0; i < n; i++){
        if (i >= k && sz(q) && q.front() == i-k) q.pop_front();
        while (sz(q) && v[q.back()] >= v[i]) q.pop_back();
        q.push_back(i);
        if (i >= k-1) r[i-k+1] = v[q.front()];
    }
}
vector<ll> rv[MAXN];
void solve(){
    int n, m, a, b; cin >> n >> m >> a >> b;
    ll s0, x, y, z; cin >> s0 >> x >> y >> z;
    vector<ll> s(n*m); s[0] = s0;
    for (int i = 1; i < n*m; i++) s[i] = (s[i-1]*x+y)%z;
    // getMins(s, 4); for (auto it : r) cout << it << ' '; cout << '\n';
    auto get = [&](int i, int j){ 
        return s[i*m+j]; 
    };
    {
        vector<ll> v;
        for (int j = 0; j < m; j++){
            v.clear();
            for (int i = 0; i < n; i++) v.push_back(get(i, j));
            getMins(v, a);
            for (int i = 0; i+a <= n; i++) rv[i].push_back(r[i]);
        }
    }
    ll ans=0;
    {
        for (int i = 0; i+a <= n; i++){
            getMins(rv[i], b);
            for (auto it : r) ans += it;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}