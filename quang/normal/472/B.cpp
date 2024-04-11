#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n, k;
int f[2020];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> f[i];
    sort(f + 1, f + n + 1);
    long long res = 0;
    for(int j = n; j > 0; j -= k) res += (1ll * f[j] - 1) * 2;
    cout << res;
    return 0;
}