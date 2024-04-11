#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, a[MAXN];
vector<int> ch[MAXN];

int chk(int c){
    int sub=1;
    for (auto nxt : ch[c]) {
        int v = chk(nxt); if (v == 0) return 0;
        sub += v;
    }
    if (a[c] >= sub) return 0;
    return sub;
}
vector<pair<int, int>> dfs(int c){
    if (!sz(ch[c])) return {{1, c}};
    vector<pair<int, int>> cans;
    int offset=0;
    for (auto nxt : ch[c]){
        vector<pair<int, int>> cur = dfs(nxt);
        for (auto it : cur) cans.push_back({it.first+offset, it.second});
        offset += sz(cur);
    }
    sort(cans.begin(), cans.end());
    vector<pair<int, int>> ret(sz(cans)+1);
    for (int i = 0; i < sz(ret); i++){
        if (i < a[c]) ret[i] = cans[i];
        else if (i == a[c]) {
            int prev = i?ret[i-1].first:0;
            ret[i] = {prev+1, c};
        } else ret[i] = {cans[i-1].first+1, cans[i-1].second};
    }
    return ret;
}
void solve(){
    cin >> n; int r=-1;
    for (int i = 0; i < n; i++){
        int p; cin >> p >> a[i], --p;
        if (p == -1) r = i;
        else ch[p].push_back(i);
    }
    if (!chk(r)) { cout <<  no; return; }
    vector<pair<int, int>> cur = dfs(r); vector<int> ans(n);
    for (auto it : cur) ans[it.second] = it.first;
    cout << yes;
    for (auto it : ans) cout << it << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t; 
    while (t--) solve();
}