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
const int MAXN = 1e2+10, MAXM = 50+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MAXP = 2e5+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m;
string s[MAXN];
bool used[MAXN];

void solve(){
    cin >> n >> m;
    vector<string> lv, rv; string mid="";
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++){
        string c; cin >> c; s[i]=c; string r = c; reverse(r.begin(), r.end());
        for (int j = 0; j < i; j++) if (!used[j] && s[j]==r){
            used[j] = 1; lv.push_back(r); rv.push_back(c);
        }
    }
    for (int i = 0; i < n; i++) if (!used[i]){
        string r = s[i]; reverse(r.begin(), r.end());
        if (r == s[i] && sz(r) > sz(mid)) mid=r;
    }
    reverse(lv.begin(), lv.end());
    string ans="";
    for (auto it : lv) ans += it;
    ans += mid;
    for (auto it : rv) ans += it;
    cout << sz(ans) << '\n' << ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t;
    while (t--) solve();
}