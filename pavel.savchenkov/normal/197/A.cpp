#include <cstdio>

using namespace std;

int a, b, r;

int main() {
 scanf("%d%d%d", &a, &b, &r);
 if  (a >= 2 * r && b >= 2 * r) puts("First"); else puts("Second");
 return 0;
}