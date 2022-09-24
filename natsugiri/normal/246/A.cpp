#include<cstdio>

int main() {
    int n;
    scanf("%d", &n);
    if (n<3) puts("-1");
    else {
	for (int i=0; i<n; i++) {
	    printf("%d ", n-i);
	}
	puts("");
    }

    return 0;
}