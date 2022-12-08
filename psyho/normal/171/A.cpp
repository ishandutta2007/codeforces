#include <cstdio>
#include <cstdlib>

int r[] = {0, 2, 3, 1, 2, 3};

int main() {
int x,y;
scanf("%d%d", &x,&y);
int z = 0;
while (y) {
z *= 10;
z += y % 10;
y /= 10;
}
printf("%d\n", z + x);
}