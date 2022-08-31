#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1015;
int n, m, k[N], cnt[N], flag[N], tot;
struct node { int val, sy; } f[N];
bool cmp(node aa, node bb) { return aa.val > bb.val; }
db C[N][N], dp[N][N];
int main() {
    scanf("%d%d", &n, &m);
    L(i, 0, 1000) C[i][0] = 1;
    L(i, 1, 1000) L(j, 1, i) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    L(i, 1, m) {
        scanf("%d", &k[i]);
        L(j, 1, k[i]) { int t; scanf("%d", &t), ++tot, f[tot].val = t, f[tot].sy = i; }
    }
    sort(f + 1, f + tot + 1, cmp);
    int col = f[n].val, ned = 0, sum = 0;
    L(i, 1, n) {
        if(f[i].val == col) ned++;
        else cnt[f[i].sy]++;
    }
    L(i, 1, tot) if(f[i].val == col) flag[f[i].sy] = 1, ++sum;
    dp[0][0] = 1;
    L(i, 1, m) {
        L(j, 0, ned) dp[i][j] += dp[i - 1][j] / C[k[i]][cnt[i]];
        if(flag[i]) L(j, 1, ned) dp[i][j] += dp[i - 1][j - 1] / C[k[i]][cnt[i] + 1];
    }
    printf("%.12lf\n", dp[m][ned] / C[sum][ned]);
    return 0;
}

// 8 6
// 5 5 4 3 2 1 // 1 / 10
// 5 5 4 3 2 1 // 1 / 10
// 3 5 3 1 // 1 / 3
// 2 3 1 // 1
// 1 3 // 1
// 1 3 // 1