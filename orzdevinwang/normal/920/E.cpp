#include<bits/stdc++.h>
#define N 200100
#define M 600
#define re register
using namespace std;
inline void write(int s) {
	if(s > 9) write(s / 10);
	putchar(s % 10 + 48);
}
char buf[1<<23],*p1=buf,*p2=buf, obuf[1<<23], *O = obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch=getchar();
	return x;
}
int n, m, cnt, minn = 1;
int mp[N], deg[N], bh[M], dy[N], f[N], sum[N], tot, fg[N], ffg;
struct edge {
    int fr, to, val;
} e[N];
bitset<N> g[M];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
    n = read(), m = read();
    for(re int i = 1; i <= n; i++) f[i] = i, sum[i] = 1;
    for(re int i = 1; i <= m; i++) e[i].fr = read(), e[i].to = read(), deg[e[i].fr]++, deg[e[i].to]++;
    for(re int i = 2; i <= n; i++) if(deg[i] < deg[minn]) minn = i;
    for(re int i = 1; i <= m; i++) {
        if(e[i].fr == minn) mp[e[i].to] = 1;
        if(e[i].to == minn) mp[e[i].fr] = 1;
    }
    for(re int i = 1; i <= n; i++){
        if(mp[i] == 1) ++tot, dy[tot] = i, bh[i] = tot;
        else if(i != minn) f[i] = minn, sum[minn] += sum[i], sum[i] = 0;
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
            ++cnt, sum[find(j)] += sum[find(u)], sum[find(u)] = 0, f[find(u)] = find(j);
        }
    }
    write(tot - cnt + 1);
    puts("");
    for(int i = 1; i <= n; i++) if(sum[i]) ++ffg, sum[ffg] = sum[i];
    sort(sum + 1, sum + ffg + 1);
    for(re int i = 1; i <= ffg; i++) write(sum[i]), putchar(' ');
    puts("");
    return 0;
}