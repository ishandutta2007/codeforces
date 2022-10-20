#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m;
    if(n * m == 1) cout << 1.0;
    else printf("%0.7f", (1.0 / n) + ( (1.0 * n - 1) * (1.0 * m - 1) / (1.0 * n) / (1.0 * m * n -1)));
    return 0;
}