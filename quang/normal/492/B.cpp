#include <bits/stdc++.h>
#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 1010;

int n, l;
long long a[N];
long long res = 0;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> l;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        if(i == 1) res = max(res, a[i] * 2);
        if(i == n)
            res = max(res, (l - a[i]) * 2);
        else res = max(res, a[i + 1] - a[i]);
    }
    printf("%0.9f", (double)res / 2);
    return 0;
}