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
const int MAXN = 7, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n, m, ans=0, c[MAXN];
vector<pair<int, int>> ed;

void perms(int i){
    if (i == n){
        unordered_set<int> s;
        for (auto it : ed){
            int x=c[it.first], y=c[it.second];
            if (x < y) swap(x, y);
            s.insert(7*x+y);
        }
        ans = max(ans, sz(s)); return;
    }
    for (int x = 1; x <= 6; x++){
        c[i] = x;
        perms(i+1);
    }
}
void solve(){
    cin >> n >> m; ed.reserve(m);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        ed.push_back({a, b});
    }
    perms(0);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}