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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e5+3, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int cnt[2]={}, n, q; cin >> n >> q;
    vector<int> a(n); for (auto& it : a) cin >> it, cnt[it]++;
    while (q--){
        int ty; cin >> ty;
        if (ty == 1){
            int i; cin >> i, --i;
            cnt[a[i]]--, cnt[a[i]^1]++;
            a[i] ^= 1;
        } else {
            int k; cin >> k;
            cout << (cnt[1] >= k) << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1; 
    //cin >> t_c;
    while (t_c--) solve();
}