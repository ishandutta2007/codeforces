#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

int hy, ay, dy, hm, am ,dm, h, a, d, ans, add;

int main() {
    ios::sync_with_stdio(0);
    cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;
    if (ay <= dm) {
        add = a * (dm + 1 - ay);
        ay = dm + 1;
    }
    ans = mod;
    REP (i, 202) REP (j, 202) {
        if (dy + j >= am) {
            ans = min(ans, j * d);
            continue;
        }
        int t = (hm - 1 + ay + i - dm) / (ay + i - dm);
        int cur = max(0, t * (am - dy - j) + 1 - hy);
        ans = min(ans, cur * h + i * a + j * d);
    }
    // BUG(add);
    cout << ans + add;
}