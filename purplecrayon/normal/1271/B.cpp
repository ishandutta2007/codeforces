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
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> pos[2];
    for (int i = 0; i < n; i++) pos[s[i]=='W'].push_back(i);
    if (!sz(pos[0]) || !sz(pos[1])) { cout << "0\n"; return; }
    if ((sz(pos[0])&1) && (sz(pos[1])&1)){ cout << "-1\n"; return; }
    if (sz(pos[1])&1) swap(pos[0], pos[1]);
    vector<int> ans;
    for (int i = 0; i < sz(pos[1]); i+= 2){
        for (int j = pos[1][i]; j < pos[1][i+1]; j++) ans.push_back(j+1);
    }
    assert(sz(ans) <= 3*n);
    cout << sz(ans) << "\n";
    for (auto it : ans) cout << it << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;// cin >> t; 
    while (t--) solve();
}