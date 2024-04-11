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
const int MAXN = 1e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, c[2], h; cin >> n >> c[0] >> c[1] >> h;
    string s; cin >> s;
    if (c[0] > c[1]){
        swap(c[0], c[1]);
        for (auto& x : s) x = x^'0'^'1';
    }
    int ans=0;
    if (c[0]+h < c[1]){
        //want to convert all ones to zeros
        int cnt=0;
        for (auto& x : s) cnt += x=='1', x='0';
        ans += cnt*h;
    }
    for (auto& x : s) ans += c[x-'0'];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}