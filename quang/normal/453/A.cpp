#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int m, n;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> m >> n;
    double res = 0.0;
    for(int i = 1; i <= m; i++)
        res += 1.0 * i * (pow(1.0 * i / m, 1.0 * n) - pow(1.0 * (i - 1) / m, 1.0 * n));
    printf("%0.4f", res);
    return 0;
}