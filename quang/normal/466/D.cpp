#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 2020, MOD = 1000000007;

int n, h;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> h;
    a[0] = 0, a[n + 1] = h;
    long long res = 1;
    for(int i = 1; i <= n + 1; i++) {
        if(i <= n) cin >> a[i];
        a[i] = h - a[i];
        if(a[i] < 0 || abs(a[i] - a[i - 1]) > 1) {
            res = 0;
            continue;
        }
        if(a[i] == a[i - 1]) res = (res * (a[i] + 1)) % MOD;
        if(a[i] < a[i - 1]) res = (res * a[i - 1]) % MOD;
    }
    cout << res;
    return 0;
}