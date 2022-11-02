#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e10;
const int max_n = 1e6 + 1;
 
struct rec {
    int x, y, a;
 
    rec() {}
    rec(int x, int y, int a) : x(x), y(y), a(a) {}
};
 
vector<pii> line;
 
bool inter(pii a, pii b, pii c) {
    return (ld)(a.se - b.se) / (b.fi - a.fi) < (ld)(a.se - c.se) / (c.fi - a.fi);
}
 
void add(pii a) {
    while (line.size() && a.fi == line.back().fi && a.se >= line.back().se) 
        line.pop_back();
 
    while(line.size() >= 2 && inter(a, line.back(), line[line.size() - 2])) 
        line.pop_back();
 
    line.emplace_back(a);
}
 
int get(int x) {
    if (line.empty()) return 0;
 
    int l = -1, r = line.size() - 1;

    int res = 0;

    while(r - l > 1) {
        int mid = (l + r) / 2;

        //res = max(res, line[mid].fi * x + line[mid].se);

        if (line[mid].fi * x + line[mid].se > line[mid + 1].fi * x + line[mid + 1].se) r = mid;
        else l = mid;
    }
    return max(res, line[r].fi * x + line[r].se); 
}
 
void solve() {
    int n;
    cin >> n;
    vector<rec> a(n);
    for(int i = 0;i < n;i++) 
        cin >> a[i].x >> a[i].y >> a[i].a;
 
    sort(all(a), [](rec v1, rec v2) {return mp(v1.x, v1.y) < mp(v2.x, v2.y);});
 
    vector<int> dp(n);
 
    for(int i = 0;i < n;i++) {
        dp[i] = get(-a[i].y) + a[i].x * a[i].y - a[i].a;
 
        //cout << dp[i] << " ";
        add({a[i].x, dp[i]});
    }
    //cout << endl;
 
    cout << dp[max_element(all(dp)) - dp.begin()];
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);
 
    solve();
}