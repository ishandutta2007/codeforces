#include <cstdio>
#include <cstdlib>

int r[] = {0, 2, 3, 1, 2, 3};

int main() {
int n;
scanf("%d%d", &n);
int a = 1;
int b = 12;
for (int i = 0; i < n - 1; i++) {
a += b;
b += 12;
}
printf("%d\n", a);
}