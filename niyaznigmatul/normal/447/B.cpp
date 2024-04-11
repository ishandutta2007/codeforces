#include <bits/stdc++.h>

int w[42], s[1234567];

int main() {
int c = getchar();
while (c <= 32) c = getchar();
int n = 0;
while (c > 32) {
s[n++] = c - 'a';
c = getchar();
}
int k;
scanf("%d", &k);
for (int i = 0; i < 26; i++) scanf("%d", w + i);
int ans = 0;
for (int i = 0; i < n; i++) ans += (i + 1) * w[s[i]];
int mx = -(1 << 30);
for (int i = 0; i < 26; i++) if (mx < w[i]) mx = w[i];
for (int i = 0; i < k; i++) ans += mx * (i + 1 + n);
printf("%d\n", ans);
}