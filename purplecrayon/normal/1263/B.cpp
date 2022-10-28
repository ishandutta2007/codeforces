#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e3+10, MAXM = 3e3+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll LINF = 1e18+10;

void solve(){
    int n; cin >> n;
    map<string, int> p; vector<string> v;
    for (int i = 0; i < n; i++){
        string s; cin >> s; v.push_back(s); p[s]++;
    }
    int ans=0;
    for (int i = 0; i < n; i++){
        if (p[v[i]] > 1) ans++;
        else { continue; }
        p[v[i]]--;
        v[i][0]='0';
        p[v[i]]++;
        while (p[v[i]] > 1){
            p[v[i]]--;
            v[i][0]++;
            p[v[i]]++;
        }
    }
    cout << ans << '\n';
    for (auto it : v) cout << it << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t; 
    while (t--) solve();
}