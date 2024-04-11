#include<bits/stdc++.h>
#define N 500010
#define FOR(i, j, k) for(int i = j; i <= k; i++) 
#define FORP(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
int n, m, a[N];
struct basis {
    int G[24];
    int h[24];
} ans[N];
basis operator + (basis aa, int pp) {
    basis res = aa;
    int bb = a[pp];
    FORP(i, 22, 0) if(bb & (1 << i)) {
            if(!res.G[i]) res.G[i] = bb, res.h[i] = pp;
            else if(pp > res.h[i]) swap(bb, res.G[i]), swap(pp, res.h[i]);
            bb ^= res.G[i];
        }
    return res;
}
int l, r;
int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]), ans[i] = ans[i - 1] + i;
    scanf("%d", &m);
    while(m--) {
        scanf("%d%d", &l, &r);
        int Ans = 0;
        FORP(i, 22, 0) if(ans[r].h[i] >= l && Ans < (Ans ^ ans[r].G[i])) Ans ^= ans[r].G[i];
        printf("%d\n", Ans);
    }
    return 0;
}