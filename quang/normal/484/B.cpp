#include <bits/stdc++.h>
#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 200100, N2 = 3000000;

int n;
int a[N], b[N];
int gtmax[N2];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int cur = 0;
    a[0] = 0;
    sort(a + 1, a + n + 1);
    for(int i= 1; i <= n; i++)
        if(a[i] != a[i - 1]) b[++cur] = a[i];
    for(int i = 1; i <= cur; i++)
        gtmax[b[i]] = b[i];
    for(int i = 1; i < N2; i++)
        gtmax[i] = max(gtmax[i], gtmax[i - 1]);
    int res = 0;
    for(int i = 1; i <= cur; i++) {
        for(int j = b[i] + b[i]; j < N2; j += b[i]) {
            int x = gtmax[j - 1];
            res = max(res, x - j + b[i]);
        }
    }
    cout << res;
    return 0;
}