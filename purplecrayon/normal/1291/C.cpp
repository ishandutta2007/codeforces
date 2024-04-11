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
typedef long long ll;
void fsc(ll &x){
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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n); for (auto& it : a) cin >> it;
    int ans=-1; 
    vector<int> val; val.reserve(n); for (auto it : a) val.push_back(it);
    sort(val.begin(), val.end());
    
    int lo=-1, hi=sz(val), mid=(lo+hi)/2;
    auto v = [&](int x) -> bool {
        for (int l = 0; l <= k; l++){ //fixing i to go to the left
            int r = k-l; //fixing r go to the right
            bool bad=0;
            int notFixed = max(m-1-k, 0);
            for (int nl = 0; nl <= notFixed; nl++){
                int nr = notFixed-nl;
                int rl = l+nl, rr = r+nr;
                // cerr << min(m-1, rl) << ' ' << max(n-1-rr, n-m) << "\n";
                if (a[min(m-1, rl)] < x && a[max(n-1-rr, n-m)] < x) bad=1;
            }
            if (!bad) return true;
        }
        return false;
    };
    // for (int i = 1; i < 10; i++) cerr << v(i);
    // cerr << '\n';
    while (lo < mid && mid < hi){
        if (v(val[mid])) lo=mid;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    cout << val[lo] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}