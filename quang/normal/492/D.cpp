#include <bits/stdc++.h>
#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 1000010;

int n, cnt = 0;
long long b[N * 2];
long long x, y, a, z;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> x >> y;
    z = __gcd(x, y);
    z = (x * y) / z;
    for(int i = 1; i <= x; i++)
        b[++cnt] = (z / x) * i;
    for(int i = 1; i <= y; i++)
        b[++cnt] = (z / y) * i;
    b[0] = b[cnt + 1] = -1;
    sort(b + 1, b + cnt + 1);
    while(n--) {
        cin >> a;
        a %= (x + y);
        if(a == 0) {
            cout << "Both\n";
            continue;
        }
        long long val = b[a];
        if((val % (z / x)) == 0 && (val % (z / y)) == 0) cout << "Both";
        if((val % (z / x)) == 0 && (val % (z / y)) != 0) cout << "Vanya";
        if((val % (z / x)) != 0 && (val % (z / y)) == 0) cout << "Vova";
        cout << endl;
    }
    return 0;
}