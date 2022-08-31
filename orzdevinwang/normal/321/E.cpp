#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int BUF=1<<20;
static char buf[BUF],*p1=buf,*p2=buf,obuf[BUF],*p3=obuf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,BUF,stdin),p1==p2)?EOF:*p1++
const int N = 4007;
int n, m, G[N][N], cnt[N], sum[N][N];
ll f[N];
vector<int> ve[N];
bool p[N];
int head, last, lef[N], rig[N];
int js(int x, int y) {
    int l = 1, r = n, ans = n + 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(f[x] - sum[mid][x] >= f[y] - sum[mid][y]) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}
void POP(int x, int id) {
    if(!p[x]) return;
    if(x == head) head = rig[x];
    if(x == last) last = lef[x];
    p[x] = 0;
    if(lef[x] != -1) rig[lef[x]] = rig[x];
    if(rig[x] != -1) lef[rig[x]] = lef[x];
    if(lef[x] == -1 || rig[x] == -1) return;
    int now = js(lef[x], rig[x]);
    if(now <= id) POP(lef[x], id);
    else if(now <= n) ve[now].push_back(lef[x]);
}
void Push(int x, int id) {
    rig[last] = x, lef[x] = last, last = x, rig[x] = -1, p[x] = 1;
    int now = js(lef[x], x);
    if(now <= id) POP(lef[x], id);
    else if(now <= n) ve[now].push_back(lef[x]);
}
int check(int x) {
    f[0] = 0, head = last = 0, lef[0] = rig[0] = -1, p[0] = 1;
    L(i, 1, n) {
        for(int p : ve[i]) POP(p, i);
        ve[i].clear();
        f[i] = f[head] - sum[i][head] + x + sum[i][i];
        cnt[i] = cnt[head] + 1;
        Push(i, i);
    }
    return cnt[n];
}
int main() {
    scanf("%d%d", &n, &m);
    L(i, 1, n) L(j, 1, n) {
        char ch = getchar(); while(ch < '0' || ch > '9') ch = getchar();
        G[i][j] = ch - '0', sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + G[i][j];
    }
    L(i, 1, n) L(j, 1, n) sum[i][j] <<= 1;
    int l = 0, r = sum[n][n]; ll ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid) >= m) ans = (f[n] - (sum[n][n] >> 1) - 1ll * mid * m) / 2, l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}