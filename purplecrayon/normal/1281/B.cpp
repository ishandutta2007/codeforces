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
    const string bad="---\n";
    string s1, s2; cin >> s1 >> s2;
    int n = sz(s1); vector<int> suff(n);
    suff[n-1] = s1[n-1]-'A';
    for (int i = n-2; i >= 0; i--){
        suff[i] = min(s1[i]-'A', suff[i+1]);
    }
    int idxSwap=-1;
    for (int i = 0; i < n && idxSwap == -1; i++){
        if (suff[i] != s1[i]-'A') idxSwap = i;
    }
    if (idxSwap != -1){
        int idx2=-1;
        for (int i = n-1; i >= 0 && idx2 == -1; i--){
            if (s1[i]-'A' == suff[idxSwap]) idx2 = i;
        }
        // cout << idxSwap << ' ' << idx2 << '\n';
        swap(s1[idxSwap], s1[idx2]);
    }
    if (s1 < s2) { cout << s1 << '\n'; }
    else cout << bad;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t; 
    while (t--) solve();
}