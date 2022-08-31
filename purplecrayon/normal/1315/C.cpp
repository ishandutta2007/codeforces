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
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MAXP = 2e5+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n; set<int> s; for (int i = 1; i <= 2*n; i++) s.insert(i);
    vector<int> a(n); for (auto& it : a) cin >> it, s.erase(it);
    vector<int> ans;
    for (int i = 0; i < n; i++){
        auto it = s.lower_bound(a[i]); if (it == s.end()){ cout << "-1\n"; return; }
        ans.push_back(a[i]), ans.push_back(*it);
        s.erase(it);
    }
    
    vector<int> t1 = ans, t2(2*n); iota(t2.begin(), t2.end(), 1); sort(t1.begin(), t1.end()); if (t1 != t2) { cout << "-1\n"; return; }
    for (auto it : ans) cout << it << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}