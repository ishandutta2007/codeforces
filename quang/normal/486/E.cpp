#include <bits/stdc++.h>
#define Task "E"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100, MAX = 1000000007;

int n, best = 0;
int a[N], Tr[N], Sau[N], dd[N], T[N], res[N];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        T[i] = MAX;
        int vt = lower_bound(T + 1, T + i + 1, a[i]) - T;
        Tr[i] = vt;
        T[vt] = a[i];
        best = max(best, Tr[i]);
    }
    for(int i = n; i; i--) {
        T[n - i + 1] = MAX;
        int vt = lower_bound(T + 1, T + n - i + 2, -a[i]) - T;
        Sau[i] = vt;
        T[vt] = -a[i];
    }
    for(int i = 1; i <= n; i++)
        if(Tr[i] + Sau[i] - 1 < best) res[i] = 1;
        else {
            res[i] = 2;
            dd[Tr[i]]++;
        }
    for(int i = 1; i <= n; i++)
        if(res[i] == 2 && dd[Tr[i]] == 1) res[i] = 3;
    for(int i = 1; i <= n; i++) cout << res[i];
    return 0;
}