#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

int n;
long double lis[111], p0, p1, p00, p11;

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    sort(lis, lis + n);
    REP (i, n / 2) swap (lis[i], lis[n - 1 - i]);
    p0 = 1;
    p1 = 0;
    REP (i, n) {
        long double p = lis[i];
        p00 = p0 * (1 - p);
        p11 = p1 * (1 - p) + p0 * p;
        // cout << p00 << ' ' << p11 << endl;
        if (p00 - p11 < eps) {
            cout << setprecision(11) << max(lis[0], p11);
            return 0;
        }
        p0 = p00;
        p1 = p11;
    }
    cout << setprecision(11) << max(p1, lis[0]);
}