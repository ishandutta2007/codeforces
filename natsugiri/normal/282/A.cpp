#include <cstdio>
int main() {
    int x=0, n;
    char s[16];
    scanf("%d", &n);
    for (;n--;) {
	scanf("%s", s);
	x+=(s[1]=='+'?1:-1);
    }
    printf("%d\n", x);
    return 0;
}