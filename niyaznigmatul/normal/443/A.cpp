#include <bits/stdc++.h>

int a[42];

int main() {
int c = getchar();
while (c != '}') {
if (c >= 'a' && c <= 'z') a[c - 'a']++;
c = getchar();
}
int ans = 0;
for (int i = 0; i < 26; i++) if (a[i] > 0) ++ans;
printf("%d\n", ans);
}