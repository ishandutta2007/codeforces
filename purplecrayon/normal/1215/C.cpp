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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> pos[2];
    for (int i = 0; i < n; i++){
        if (s[i] == 'a' && t[i] == 'b') pos[0].push_back(i);
        else if (s[i] == 'b' && t[i] == 'a') pos[1].push_back(i);
    }
    if ((sz(pos[0])+sz(pos[1]))&1){ cout << "-1\n"; return; }
    if (sz(pos[0]) < sz(pos[1])) swap(pos[0], pos[1]);
    vector<pair<int, int>> ops;
    if (sz(pos[0])&1){
        int x = pos[0].back(); pos[0].pop_back();
        pos[1].push_back(x);
        ops.push_back({x, x});
    }
    for (auto j : {0, 1}) for (int i = 0; i < sz(pos[j]); i+=2) ops.push_back({pos[j][i], pos[j][i+1]});
    cout << sz(ops) << '\n';
    for (auto it : ops) cout << (it.first+1) << ' ' << (it.second+1) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}