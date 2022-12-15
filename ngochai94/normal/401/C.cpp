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

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    if (n > m + 1 || m > 2 * (n + 1)) {
        cout << -1;
        return 0;
    }
    if (n == m) {
        REP (i, n) cout << "10";
    } else if (n > m) {
        cout << '0';
        REP (i, n - 1) cout << "10";
    } else {
        int tmp = m - n - 1;
        int cnt = tmp;
        REP (i, min(tmp, n)) {
            cout << "110";
            cnt--;
        }
        if (cnt) cout << "11";
        else {
            REP (i, n - tmp) cout << "10";
            cout << 1;
        }
    }
}