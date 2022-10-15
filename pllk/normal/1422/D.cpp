#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int n, m;
ll sx, sy, fx, fy;
ll x[101010];
ll y[101010];
set<pair<ll,int>> zx;
set<pair<ll,int>> zy;
ll d[101010];
int z[101010];
priority_queue<pair<ll,int>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> sx >> sy >> fx >> fy;
    x[0] = sx;
    y[0] = sy;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        zx.insert({x[i],i});
        zy.insert({y[i],i});
        d[i] = 1e18;
    }
    ll r = 1e18;
    q.push({0,0});
    while (q.size()) {
        auto t = q.top(); q.pop();
        if (z[t.second]) continue;
        z[t.second] = 1;
        ll ux = x[t.second];
        ll uy = y[t.second];
        ll ud = -t.first;
        r = min(r,ud+abs(ux-fx)+abs(uy-fy));
        if (t.second != 0) {
            zx.erase({ux,t.second});
            zy.erase({uy,t.second});
        }
        ll dd;
        auto it = zx.lower_bound({ux,0});
        if (it != zx.end()) {
            dd = ud+abs(ux-it->first);
            if (dd < d[it->second]) {
                d[it->second] = dd;
                q.push({-dd,it->second});
            }
        }
        if (it != zx.begin()) {
            it--;
            dd = ud+abs(ux-it->first);
            if (dd < d[it->second]) {
                d[it->second] = dd;
                q.push({-dd,it->second});
            }
        }
        it = zy.lower_bound({uy,0});
        if (it != zy.end()) {
            dd = ud+abs(uy-it->first);
            if (dd < d[it->second]) {
                d[it->second] = dd;
                q.push({-dd,it->second});
            }
        }
        if (it != zy.begin()) {
            it--;
            dd = ud+abs(uy-it->first);
            if (dd < d[it->second]) {
                d[it->second] = dd;
                q.push({-dd,it->second});
            }
        }
    }
    cout << r << "\n";
}