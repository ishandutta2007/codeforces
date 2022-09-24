#include<cstdio>

int main() {
    int n, a, g, sa=0, sg=0;

    scanf("%d", &n);
    for (;n--;) {
	scanf("%d%d", &a, &g);
	if (sa+a-sg>500) {
	    putchar('G');
	    sg+=g;
	} else {
	    putchar('A');
	    sa+=a;
	}
    }
    putchar('\n');
    return 0;
}