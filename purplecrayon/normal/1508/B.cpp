#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

ll cnt(int x){ return x >= 63 ? INF : 1ll<<(max(x, 1)-1); }
void solve(){
    int n; ll k; cin >> n >> k;
    if (cnt(n) < k){ cout << -1 << '\n'; return; }
    int one = 1;
    for (int i = 0; i < n; ) {
        int left = n-i;
        if (left == 1){ cout << one << '\n'; return; }

        for (int dec = 1; ; dec++) {
            if (cnt(left-dec) >= k) {
                for (int i = dec+one-1; i >= one; i--) cout << i << ' ';
                one += dec;
                i += dec;
                break;
            } else k -= cnt(left-dec);
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}