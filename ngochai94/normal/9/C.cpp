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

int n, ans;
char c[10];

void f(int x) {
    if (x == 10) {
        int res = 0;
        REP (i, 10) {
            res *= 10;
            if (c[i] == '1') res++;
        }
        if (res <= n) {
            ans++;
            // REP (i, 10) cout << c[i]; cout << endl;
        }
        return;
    }
    c[x] = '0';
    f(x + 1);
    c[x] = '1';
    f(x + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    f(0);
    cout << ans - 1;
}