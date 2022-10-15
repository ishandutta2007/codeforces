#include <bits/stdc++.h>

int p[1234];

int main() {
int n, m;
scanf("%d%d", &n, &m);
long long ans = 1;
for (int i = 0; i < n; i++) p[i] = i;
for (int i = 0; i < m; i++) {
int v, u;
scanf("%d%d", &v, &u);
while (v != p[v]) v = p[v];
while (u != p[u]) u = p[u];
if (u != v) ans *= 2;
p[v] = u;
}
printf("%lld\n", ans);
}