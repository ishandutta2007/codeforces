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
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    ll k; cin >> k;
    if (k&1){
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    for (int i=1; i<62; i++) if (k&(1ll<<i)) {
        ans.push_back(1);
        if (i>1) {
            for (int j = 0; j < i-2; j++) ans.push_back(0);
            ans.push_back(1);
        }
        k ^= 1ll<<i;
    }
    cout << sz(ans) << '\n';
    for (auto& it : ans) cout << it << ' '; cout << '\n';
    assert(!k);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}