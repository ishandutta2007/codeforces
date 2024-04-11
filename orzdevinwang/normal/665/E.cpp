#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 7;
int n, k, a[N], ch[N << 5][2], val[N << 5], tot = 1, v;
ll ans = 0;
int main() {
    scanf("%d%d", &n, &k), --k;
    int now = 1;
    for(int j = 30; j >= 0; j--) now = ch[now][0] = ++tot, val[now]++;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int now = 1;
        v ^= a[i];
        for(int j = 30; j >= 0; j--) {
            int ta = ((v >> j) & 1), tk = ((k >> j) & 1);
            if(tk) now = ch[now][1 ^ ta];
            if(!tk) ans += val[ch[now][1 ^ ta]], now = ch[now][ta];
            if(now == 0) break;
        }
        now = 1;
        for(int j = 30; j >= 0; j--) {
            if(!ch[now][(v >> j) & 1]) ch[now][(v >> j) & 1] = ++tot;
            now = ch[now][(v >> j) & 1], val[now]++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}