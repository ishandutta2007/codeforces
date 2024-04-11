#include <bits/stdc++.h>

int s[1234567];

int main() {
int c = getchar();
while (c <= 32) c = getchar();
int n = 0;
while (c > 32) {
s[n++] = c;
c = getchar();
}
int k;
scanf("%d", &k);
n += k;
int ans = 0;
for (int len = 1; len * 2 <= n; len++) {
bool can = false;
for (int start = 0; start + len * 2 <= n; start++) {
bool eq = true;
for (int i = 0; i < len; i++) {
if (s[start + i] == 0 || s[start + i + len] == 0) continue;
if (s[start + i] != s[start + i + len]) {
eq = false;
break;
}
}
if (eq) {
can = true;
break;
}
}
if (can) ans = len;
}
printf("%d\n", 2 * ans);
}