#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--) 
#define ll long long 
#define db double 
using namespace std;
const int N = 3007;
const int M = 1e6 + 7;
int n, m, len[N];
ll ff[M], init[N][N], ans;
void work(int l, int r, ll *f) {
    if(l == r) {
        L(i, 0, len[l]) ans = max(ans, init[l][i] + f[m - i]);
        return;
    }
    int mid = (l + r) / 2;
    ll ga[N] = {}, gb[N] = {};
    L(i, 0, m) ga[i] = gb[i] = f[i];
    L(i, mid + 1, r) R(j, m, len[i]) ga[j] = max(ga[j], init[i][len[i]] + ga[j - len[i]]);
    work(l, mid, ga);
    L(i, l, mid) R(j, m, len[i]) gb[j] = max(gb[j], init[i][len[i]] + gb[j - len[i]]);
    work(mid + 1, r, gb);
}
int main() {
    scanf("%d%d", &n, &m);
    L(t, 1, n) {
        scanf("%d", &len[t]);
        L(i, 1, len[t]) scanf("%lld", &ff[i]), ff[i] += ff[i - 1];
        len[t] = min(len[t], m);
        L(i, 1, len[t]) init[t][i] = ff[i];
    }
    ll ys[N] = {};
    L(i, 1, m) ys[i] = -1e16;
    work(1, n, ys);
    printf("%lld\n", ans);
    return 0;
}