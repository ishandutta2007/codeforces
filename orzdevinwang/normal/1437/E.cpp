#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 1e6 + 7;
const int inf = 1e9;
int n, k, a[N], tot, f[N];
int solve(int l, int r) {
    if(a[r] < a[l]) printf("-1\n"), exit(0);
    L(i, 0, r - l + 1) f[i] = inf;
    tot = 1, f[1] = a[l];
    L(i, l + 1, r) {
        if(a[i] < a[l]) continue;
        int u = 1, v = tot, ans = 1;
        while(u <= v) {
            int mid = (u + v) / 2;
            if(f[mid] <= a[i]) ans = mid, u = mid + 1;
            else v = mid - 1;
        }
        ans++;
        f[ans] = min(f[ans], a[i]);
        tot = max(tot, ans);
        if(i == r) return r - l + 1 - ans;
    }
}
int main() {
    int ans = 0;
    scanf("%d%d", &n, &k);
    L(i, 1, n) scanf("%d", &a[i]), a[i] -= i;
    int las = 0, now = 1;
    a[0] = - n - 1, a[n + 1] = inf + n;
    L(i, 1, k) scanf("%d", &now), ans += solve(las, now), las = now;
    ans += solve(las, n + 1);
    printf("%d\n", ans);
	return 0;
}