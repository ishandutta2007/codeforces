#include<bits/stdc++.h>
#define N 110000
#define M 500
#define re register
using namespace std;
int n, m, cnt, minn = 1;
int mp[N], deg[N], bh[M], dy[N], f[N], tot;
struct edge {
    int fr, to, val;
} e[N];
bitset<N> g[M];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
inline int read() {
	char c = getchar();int x = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c  <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
	return x;
}
int main() {
    n = read(), m = read();
    for(re int i = 1; i <= n; i++) f[i] = i;
    for(re int i = 1; i <= m; i++) e[i].fr = read(), e[i].to = read(), deg[e[i].fr]++, deg[e[i].to]++;
    for(re int i = 2; i <= n; i++) if(deg[i] < deg[minn]) minn = i;
    for(re int i = 1; i <= m; i++) {
        if(e[i].fr == minn) mp[e[i].to] = 1;
        if(e[i].to == minn) mp[e[i].fr] = 1;
    }
    for(re int i = 1; i <= n; i++){
        if(mp[i] == 1) ++tot, dy[tot] = i, bh[i] = tot;
        else f[i] = minn;
    }   
    for(re int i = 1; i <= m; i++) {
        if(mp[e[i].fr] == 1) g[bh[e[i].fr]][e[i].to] = 1;
        if(mp[e[i].to] == 1) g[bh[e[i].to]][e[i].fr] = 1;
    }
    for(re int i = 1; i <= tot; i++) {
        int u = dy[i];
        for(re int j = 1; j <= n; j++) {
            if(g[i][j]) continue;
            if(find(u) == find(j)) continue;
            ++cnt, f[find(u)] = find(j);
        }
    }
    printf("%d\n", tot - cnt);
    return 0;
}