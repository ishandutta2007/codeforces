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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

void solve(){
    int n;  cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    vector<pair<int, int>> pos{{1, 0}, {0, 1}, {2, 0}, {1, 1}, {0, 2}};
    int mask=0, x = pos.size();
    for (int i = 0; i < x; i++) if (g[pos[i].first][pos[i].second]-'0') mask ^= 1<<i;
    for (int i = 0; i < (1<<x); i++) if (__builtin_popcount(i) <= 2){
        int nm = mask ^ i; bool bad=0;
        for (int j = 0; j < 2 && !bad; j++) for (int k = 2; k < x && !bad; k++) if (((nm>>j)&1)==(nm>>k&1)) bad=1;
        if (!bad){
            vector<int> ch;
            for (int j = 0; j < x; j++) if (i&(1<<j)) ch.push_back(j);
            cout << sz(ch) << '\n';
            for (auto it : ch) cout << (pos[it].first+1) << ' ' << (pos[it].second+1) << '\n';
            return;
        }
    }
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}