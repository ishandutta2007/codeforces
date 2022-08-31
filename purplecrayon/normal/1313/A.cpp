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

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MAXP = 2e5+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int a[3]; cin >> a[0] >> a[1] >> a[2];
    vector<int> v;
    for (int i = 1; i < (1<<3); i++) v.push_back(i);
    int ans=0;
    do {
        int n[3] = {a[0], a[1], a[2]}, cur=0;
        for (auto it : v) {
            bool bad=0;
            if (it&(1<<0)){
                bad |= n[0] <= 0;
            }
            if (it&(1<<1)){
                bad |= n[1] <= 0;
            }
            if (it&(1<<2)){
                bad |= n[2] <= 0;
            }
            if (bad) continue;
            if (it&(1<<0)){
                n[0]--;
            }
            if (it&(1<<1)){
                n[1]--;
            }
            if (it&(1<<2)){
                n[2]--;
            }
            cur++;
        }
        ans = max(ans, cur);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}