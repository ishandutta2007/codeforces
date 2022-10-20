#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

long long n;
long long gtmin , gtmax;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    gtmin = gtmax = (n + 1) * 9 - n;
    for(long long i = 1; i * i * i <= n; i++) {
        if(n % i) continue;
        for(long long j = 1; i * j * j <= n; j++) {
            if((n / i) % j) continue;
            gtmin = min((i + 1) * (j + 2) * (n / i / j + 2) - n, gtmin);
        }
    }
    cout << gtmin << " " << gtmax;
    return 0;
}