#include<bits/stdc++.h>
#define N 110000
#define M 1100000
#define ll long long
using namespace std;
int n, m, k, u = 1, v, kuai, a[N], g[N], mpa[M], mpb[M];
ll ans;
struct node {
    int u, v, id;
    ll ans;
} ask[N];
bool cmp(node aa, node bb) {
    if(aa.u / kuai == bb.u / kuai) return aa.v < bb.v;
    else return aa.u < bb.u;
}
bool pmc(node aa, node bb) {
    return aa.id < bb.id;
}
void js(int x) {
    --mpa[g[x - 1]], --mpb[g[x]];
}
void zj(int x) {
    ++mpa[g[x - 1]], ++mpb[g[x]];
}
int main() {
    scanf("%d%d%d", &n, &m, &k), kuai = sqrt(n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), g[i] = g[i-1] ^ a[i];
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &ask[i].u, &ask[i].v);
        ask[i].id = i;
    }
    sort(ask + 1, ask + m + 1, cmp);
    for(int i = 1; i <= m; i++) {
        while(u > ask[i].u) --u, zj(u), ans += mpb[k ^ g[u - 1]];
        while(u < ask[i].u) ans -= mpb[k ^ g[u - 1]], js(u), ++u;
        while(v > ask[i].v) ans -= mpa[k ^ g[v]], js(v), --v;
        while(v < ask[i].v) ++v, zj(v), ans += mpa[k ^ g[v]];
        ask[i].ans = ans;
    }
    sort(ask + 1, ask + m + 1, pmc);
    for(int i = 1; i <= m; i++) printf("%lld\n", ask[i].ans);
    return 0;
}