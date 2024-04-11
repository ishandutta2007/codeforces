#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long
#define db double
#define mp make_pair
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
const int P = 8;
int n, p, k, cnt[1 << P];
ll dp[1 << P], sum;
struct node { int a, s[P]; } f[N];
bool cmp(node aa, node bb) { return aa.a > bb.a; }
int main() {
    scanf("%d%d%d", &n, &p, &k);
    L(i, 1, n) scanf("%d", &f[i].a);
    L(i, 1, n) L(j, 1, p) scanf("%d", &f[i].s[j]);
    sort(f + 1, f + n + 1, cmp);
    L(i, 0, (1 << p) - 1) cnt[i] = cnt[i >> 1] + (i & 1);
    L(i, 1, k) sum += f[i].a;
    dp[0] = sum;
    L(i, 1, n) L(j, 0, (1 << p) - 1) {
        if(cnt[j] + k >= i) {
            L(d, 1, p) if(!((1 << (d - 1)) & j)) {
                int ss = (j | (1 << (d - 1)));
                dp[ss] = max(dp[ss], dp[j] + f[i].s[d] - f[i].a + f[cnt[j] + k + 1].a);
            }
        }
        else {
            L(d, 1, p) if(!((1 << (d - 1)) & j)) {
                int ss = (j | (1 << (d - 1)));
                dp[ss] = max(dp[ss], dp[j] + f[i].s[d]);
            }
        }
    }
    printf("%lld\n", dp[(1 << p) - 1]);
    return 0;
}