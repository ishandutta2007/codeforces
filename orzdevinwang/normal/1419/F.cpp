#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define int long long
using namespace std;
const int N = 1e3 + 7;
int n, x[N], y[N], fx[N], fy[N], f[N];
int arrx[N], totx, arry[N], toty;
int Gx1[N][N], Gy1[N][N], Gx2[N][N], Gy2[N][N];
bool cheak(int i, int j, int X) {
    if((x[i] == x[j] && abs(y[i] - y[j]) <= X) || (y[i] == y[j] && abs(x[i] - x[j]) <= X)) return 1;
    else return 0;
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
bool check(ll X) {
    L(i, 1, n) f[i] = i;
    int cnt = n;
    L(i, 1, n) L(j, i + 1, n) if(cheak(i, j, X)) if(find(i) != find(j)) f[find(i)] = find(j), cnt --;
    if(cnt > 4) return 0;
    L(i, 1, totx) L(j, 1, toty) {
        int lx = Gx1[i][j], rx = Gx2[i][j], ly = Gy1[i][j], ry = Gy2[i][j];
        int T[6] = {}, TOT = 0;
        x[n + 1] = arrx[i], y[n + 1] = arry[j];
        if(lx && cheak(lx, n + 1, X)) T[++TOT] = find(lx);
        if(rx && cheak(rx, n + 1, X)) T[++TOT] = find(rx);
        if(ly && cheak(ly, n + 1, X)) T[++TOT] = find(ly);
        if(ry && cheak(ry, n + 1, X)) T[++TOT] = find(ry);
        sort(T + 1, T + TOT + 1);
        TOT = unique(T + 1, T + TOT + 1) - T - 1;
        if(cnt == TOT) return 1;
    }
    if(cnt > 2) return 0;
    L(i, 1, n) L(j, i + 1, n) if(cheak(i, j, X * 2)) if(find(i) != find(j)) return 1;
    return 0;
}
signed main() {
    scanf("%lld", &n);
    L(i, 1, n) scanf("%lld%lld", &x[i], &y[i]), arrx[++totx] = x[i], arry[++toty] = y[i];
    sort(arrx + 1, arrx + totx + 1);
    totx = unique(arrx + 1, arrx + totx + 1) - arrx - 1;
    sort(arry + 1, arry + toty + 1);
    toty = unique(arry + 1, arry + toty + 1) - arry - 1;
    L(i, 1, n) {
        fx[i] = lower_bound(arrx + 1, arrx + totx + 1, x[i]) - arrx;
        fy[i] = lower_bound(arry + 1, arry + toty + 1, y[i]) - arry;
        Gx1[fx[i]][fy[i]] = Gy1[fx[i]][fy[i]] = Gx2[fx[i]][fy[i]] = Gy2[fx[i]][fy[i]] = i;
    }
    L(i, 1, n) L(j, 1, n) {
        if(!Gx1[i][j]) Gx1[i][j] = Gx1[i][j - 1];
        if(!Gy1[i][j]) Gy1[i][j] = Gy1[i - 1][j];
    }
    R(i, n, 1) R(j, n, 1) {
        if(!Gx2[i][j]) Gx2[i][j] = Gx2[i][j + 1];
        if(!Gy2[i][j]) Gy2[i][j] = Gy2[i + 1][j];
    }
    ll L = 0, R = 2e9, res = 2e9 + 7;
    while(L <= R) {
        ll mid = (L + R) / 2;
        if(check(mid)) res = mid, R = mid - 1;
        else L = mid + 1;
    }
    if(res > 2e9) printf("-1\n");
    else printf("%lld\n", res);
    return 0;
}