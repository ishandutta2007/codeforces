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
const int MAXN = 1e6+10, MAXM = 3e3+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll LINF = 1e18+10;

void solve(){
    int n, k; string s; cin >> n >> k >> s;
    k--;
    //() -> k times, the rest is ((((()))))
    string res(n, ' ');
    for (int i = 0; i < k; i++) res[2*i]='(', res[2*i+1]=')';
    for (int i = 2*k; i < n; i++){
        if (i-2*k < n/2-k) res[i] = '(';
        else res[i] = ')';
    }
    //need to get to res
    //i, j
    //abcde
    //edcba
    //ebcda
    vector<int> pos[2];
    for (int i = 0; i < n; i++){
        if (res[i] == '(' && s[i] == ')') pos[0].push_back(i);
        else if (res[i] == ')' && s[i] == '(') pos[1].push_back(i);
    }
    assert(sz(pos[0])==sz(pos[1]));
    vector<pair<int, int>> ans;
    auto swapOp = [&](int i, int j) {
        if (i > j) swap(i, j);
        ans.push_back({i, j});
        if (i+1 < j-1) ans.push_back({i+1, j-1});
    };
    for (int i = 0; i < sz(pos[0]); i++) swapOp(pos[0][i], pos[1][i]);
    assert(sz(ans)<=n);
    cout << sz(ans) << '\n';
    for (auto it : ans) cout << (it.first+1) << ' ' << (it.second+1) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t; 
    while (t--) solve();
}