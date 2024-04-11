#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

map <int, int> M;

int n;
int gtmax = -1, gtmin = 1e9 + 10;

int main()
{
   // fi, fo;
    M.clear();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        M[x]++;
        gtmax = max(gtmax, x);
        gtmin = min(gtmin, x);
    }
    long long res = 0;
    if(gtmax == gtmin) {
        res = 1ll * M[gtmax] * (M[gtmax] - 1) / 2;
        cout << 0 << " " << res;
        return 0;
    }
    res = 1ll * M[gtmax] * M[gtmin];
    cout << gtmax - gtmin << " "  << res;
    return 0;
}