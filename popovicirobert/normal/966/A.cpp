#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int INF = (int) 1e9;
const int MAXN = (int) 1e5;

int l[MAXN + 1], e[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, cl, ce, v, q, x1, y1, x2, y2;
    ios::sync_with_stdio(false);
    cin >> n >> m >> cl >> ce >> v;
    for(i = 1; i <= cl; i++) {
        cin >> l[i];
    }
    for(i = 1; i <= ce; i++) {
        cin >> e[i];
    }
    sort(l + 1, l + cl + 1);
    sort(e + 1, e + ce + 1);
    cin >> q;
    while(q > 0) {
        q--;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = INF;
        if(x1 == x2)
            ans = abs(y2 - y1);
        else {
            int res = 0;
            for(int step = 1 << 17; step; step >>= 1) {
                if(res + step <= cl && l[res + step] <= y1)
                    res += step;
            }
            if(res > 0)
                ans = min(ans, abs(y1 - l[res]) + abs(l[res] - y2) + abs(x2 - x1));
            if(res < cl) {
                res++;
                ans = min(ans, abs(y1 - l[res]) + abs(l[res] - y2) + abs(x2 - x1));
            }
            res = 0;
            for(int step = 1 << 17; step; step >>= 1) {
                if(res + step <= ce && e[res + step] <= y1)
                    res += step;
            }
            if(res > 0)
                ans = min(ans, abs(y1 - e[res]) + abs(e[res] - y2) + (abs(x2 - x1) + v - 1) / v);
            if(res < ce) {
                res++;
                ans = min(ans, abs(y1 - e[res]) + abs(e[res] - y2) + (abs(x2 - x1) + v - 1) / v);
            }
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}