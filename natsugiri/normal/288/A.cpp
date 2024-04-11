#include<cstdio>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    if (n<m) { puts("-1"); return 0; }
    if (m==1) {
	if (n>1) { puts("-1"); return 0; }
	puts("a"); return 0;
    }

    for (int i=0; i<n-m+2; i++) putchar(i%2?'b':'a');
    for (int i=0; i<m-2; i++) putchar('c'+i);
    putchar('\n');
    return 0;
}