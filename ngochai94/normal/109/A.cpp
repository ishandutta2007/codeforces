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

int n;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n / 4 + 4) {
        if (n >= i * 4 && (n - i * 4) % 7 == 0) {
            REP (j, i) cout << 4;
            REP (j, (n - i * 4) / 7) cout << 7;
            return 0;
        }
    }
    cout << -1;
}