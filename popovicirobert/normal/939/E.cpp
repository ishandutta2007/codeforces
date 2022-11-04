#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 5e5;

struct Line {
    double a, b;
}lines[MAXN + 1];

int stk[MAXN + 1];

inline double inter(Line l1, Line l2) {
    if(l1.a == l2.a)
        return 1.0 * INF;
    return 1.0 * (l2.b - l1.b) / (l1.a - l2.a);
}

inline double get(Line l, double x) {
    return l.a * x + l.b;
}

char lg[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q, type, x;
    ios::sync_with_stdio(false);
    cin >> q;
    for(int i = 2; i <= q; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    double ans = 0;
    int last, n = 0, sz = 0;
    ll sum = 0;
    while(q > 0) {
        q--;
        cin >> type;
        if(type == 1) {
            cin >> x;
            sum += x;
            lines[++n] = {1.0 * n / (n + 1), -1.0 * sum / (n + 1)};
            while(sz >= 2 && inter(lines[stk[sz - 1]], lines[stk[sz]]) - inter(lines[stk[sz - 1]], lines[n]) >= 0) {
                sz--;
            }
            stk[++sz] = n;
            last = x;
        }
        else {
            int res = 0;
            for(int step = 1 << lg[sz]; step; step >>= 1) {
                if(res + step < sz && last - inter(lines[stk[res + step]], lines[stk[res + step + 1]]) >= 0)
                    res += step;
            }
            res++;
            ans = max(ans, get(lines[stk[res]], last));
            cout << setprecision(20) << ans << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}