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
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 17, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


void solve(){
    int k; cin >> k; vector<char> v{'a', 'e', 'i', 'o', 'u'};
    for (int a = 1; a*a <= k; a++) if (k%a == 0 && min(a, k/a) >= 5){
        int n=a, m = k/a;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (j < 5) cout << v[(j+i)%5];
                else cout << v[i%5];
            }
        }
        return;
    }
    cout << "-1\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}