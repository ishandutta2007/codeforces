#include <bits/stdc++.h>

int main() {
int n, m;
scanf("%d%d", &n, &m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
int c = getchar();
while (c <= 32) c = getchar();
if (c == '-') putchar(c); else
putchar("WB"[(i + j) & 1]);
}
puts("");
}
}