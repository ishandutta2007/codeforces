#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

long long n, a, b;
long long res, ar, br, ansa, ansb;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> a >> b;
    ar = min(a, b), br = max(a, b);
    n *= 6;
    if(a * b >= n) {
        cout << a * b << endl;
        cout << a << " " << b;
        return 0;
    }
    res = 1234567897345ll;
    for(long long i = ar; i * i <= n; i++) {
        long long daib = ceil(1.0 * n / i);
        if(daib >= br)
        if(res > daib * i) {
            res = daib * i;
            ansa = i;
            ansb = daib;
        }
    }
    if(a > b) swap(ansa, ansb);
    cout << res << endl;
    cout << ansa << " " << ansb;
    return 0;
}