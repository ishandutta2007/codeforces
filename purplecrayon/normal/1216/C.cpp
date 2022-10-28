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
const int MAXN = 2e2+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 95542721, MAXK = 1e2+10,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

void solve(){
    ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    for (int rep : {0, 1}) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        if (b <= y1 && d >= y2) {
            if (x1 >= a) x1 = max(x1, c);
            if (x2 <= c) x2 = min(x2, a);
        }
        if (a <= x1 && c >= x2) {
            if (y1 >= b) y1 = max(y1, d);
            if (y2 <= d) y2 = min(y2, b);
        }
    }
    cout << (x2 > x1 || y2 > y1 ? yes : no);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}