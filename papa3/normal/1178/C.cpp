#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 998244353ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

int pot(int n, int k) {
    int res = 1;
    while (k) {
        if (k % 2) {
            res = res * n % mod;
        }
        n = n * n % mod;
        k /= 2;
    }

    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w, h;
    cin >> w >> h;

    int res = 0;
    cout << pot(2, w + h) % mod;

    return 0;
}
/*

*/