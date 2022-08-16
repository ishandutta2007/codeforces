#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2.5e2+10, MAXM = 1e5+10, MAXL = 17, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; string s; cin >> n >> s;
    int ans=1e9;
    const string need = "ACTG";
    for (int i = 0; i+4 <= n; i++){
        string cur = s.substr(i, 4); int cans=0;
        for (int j = 0; j < 4; j++) {
            int a = need[j]-'A', b = cur[j]-'A'; if (a < b) swap(a, b);
            int cc = 0;
            while (a != b) a++, a %= 26, cc++;
            cans += min(cc, abs(need[j]-cur[j]));
        }
        ans = min(ans, cans);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}