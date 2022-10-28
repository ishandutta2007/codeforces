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
    int n, m; cin >> n >> m;
    vector<string> g(n);
    vector<ar<int, 4>> v(26);
    for (auto& it : v) it = ar<int, 4>{-1, -1, -1, -1};
    for (int i = 0; i < n; i++){
        cin >> g[i];
        for (int j = 0; j < m; j++) if (g[i][j] != '.') {
            int c = g[i][j]-'a';
            if (v[c] == ar<int, 4>{-1, -1, -1, -1}) { v[c] = ar<int, 4>{i, i, j, j}; continue; }
            v[c][0] = min(v[c][0], i), v[c][1] = max(v[c][1], i);
            v[c][2] = min(v[c][2], j), v[c][3] = max(v[c][3], j);
        }
    }
    for (int i = 24; i >= 0; i--)  if (v[i] == ar<int, 4>{-1, -1, -1, -1}) v[i] = v[i+1];
    for (auto it : v) if (it[0]!=it[1] && it[2]!=it[3]){ cout << no; return; }
    vector<string> ng(n);
    for (auto& it : ng) it = string(m, '.');
    for (int c = 0; c < 26; c++) if (v[c] != ar<int, 4>{-1, -1, -1, -1}) {
        auto it = v[c];
        for (int i = it[0]; i <= it[1]; i++) for (int j = it[2]; j <= it[3]; j++) ng[i][j] = char(c+'a');
    }
    for (int i = 0; i < n; i++) if (g[i] != ng[i]){ cout << no; return; }
    cout << yes;
    int k=0; for (auto it : v)  if (it != ar<int, 4>{-1, -1, -1, -1}) k++;
    cout << k << '\n';
    for (int c = 0; c < k; c++){
        auto it = v[c];
        cout << (it[0]+1) << ' ' << (it[2]+1) << ' ' << (it[1]+1) << ' ' << (it[3]+1) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}