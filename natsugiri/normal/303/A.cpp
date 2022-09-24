#include<cstdio>
int main() {
    int n;
    scanf("%d", &n);
    if (n%2) {
	for (int i=0; i<n; i++) printf("%d%c", i, i+1==n?'\n':' ');
	for (int i=0; i<n; i++) printf("%d%c", i, i+1==n?'\n':' ');
	for (int i=0; i<n; i++) printf("%d%c", i*2%n, i+1==n?'\n':' ');
    } else puts("-1");

    return 0;
}