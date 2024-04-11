#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 5050, MAX = 1000000000;

struct data {
    int type, l, r, d;
} a[N];

int n, m;
int gtmax[N], tang[N];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) gtmax[i] = MAX;
    memset(tang, 0, sizeof(tang));
    for(int i = 1; i <= m; i++) {
        cin >> a[i].type >> a[i].l >> a[i].r >> a[i].d;
        if(a[i].type == 1)
            for(int j = a[i].l; j <= a[i].r; j++)
                tang[j] += a[i].d;
        else
            for(int j = a[i].l; j <= a[i].r; j++)
                gtmax[j] = min(gtmax[j], a[i].d - tang[j]);
    }
    memset(tang, 0, sizeof(tang));
    for(int i = 1; i <= m; i++) {
        if(a[i].type == 1)
            for(int j = a[i].l; j <= a[i].r; j++)
                tang[j] += a[i].d;
        else {
            int M = -MAX;
            for(int j = a[i].l; j <= a[i].r; j++)
                M = max(M, gtmax[j] + tang[j]);
            if(M != a[i].d) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << gtmax[i] << " ";
    return 0;
}