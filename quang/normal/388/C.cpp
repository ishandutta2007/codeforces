#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n, m, Ciel, Jiro;
int a[110], b[110], d = 0;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        for(int j = 1; j <= m; j++) cin >> b[j];
        for(int j = 1; j <= m / 2; j++) {
            Ciel += b[j];
            Jiro += b[m - j + 1];
        }
        if(m % 2) a[++d] = b[m / 2 + 1];
    }
    sort(a + 1, a + d + 1, greater<int>());
    for(int i = 1; i <= d; i++)
    if(i % 2) Ciel += a[i];
    else Jiro += a[i];
    cout << Ciel << " " << Jiro;
    return 0;
}