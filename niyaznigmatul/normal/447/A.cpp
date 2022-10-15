#include <bits/stdc++.h>

int was[333];

int main() {
int n, p;
scanf("%d%d", &p, &n);
for (int i = 0; i < n; i++) {
int x;
scanf("%d", &x);
x %= p;
if (was[x]) {
printf("%d\n", i + 1);
return 0;
}
was[x] = true;
}
puts("-1");
}