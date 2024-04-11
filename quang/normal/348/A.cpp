#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    int n, x, m = -1;
    long long s = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x, s += 1ll * x, m = max(m, x);
    cout << max((s - 1) / (n - 1) + 1, 1ll * m);
    return 0;
}