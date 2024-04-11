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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;
 
void solve(){
    string a, b; cin >> a >> b;
    for (int len = min(sz(a), sz(b)); len > 0; len--) {
        for (int i = 0; i+len <= sz(a); i++) for (int j = 0; j+len <= sz(b); j++) {
            if (a.substr(i, len) == b.substr(j, len)) {
                cout << sz(a)+sz(b)-2*len << '\n';
                return;
            }
        }
    }
    cout << sz(a)+sz(b) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}