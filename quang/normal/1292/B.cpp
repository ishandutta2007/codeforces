#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 3e16;
 
long long x, y, ax, ay, bx, by;
long long xs, ys, t;
vector<pair<long long, long long>> ls;
 
long long getDist(pair<long long, long long> u, pair<long long, long long> v) {
    return abs(u.first - v.first) + abs(u.second - v.second);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> x >> y >> ax >> ay >> bx >> by;   
    cin >> xs >> ys >> t;
    while (1) {
        if (x > INF || y > INF) break;
        ls.push_back({x, y});
        x = x * ax + bx;
        y = y * ay + by;
    }
    int res = 0;
    for (int i = 0; i < ls.size(); i++) {
        long long cur = 0;
        for (int j = i; j < ls.size(); j++) {
            if (j > i) cur += getDist(ls[j - 1], ls[j]);
            if (cur > t) break;
            long long now = min(getDist(ls[i], {xs, ys}), getDist(ls[j], {xs, ys}));
            if (cur + now <= t) res = max(res, j - i + 1);
        }
    }
    cout << res << endl;
    return 0;
}