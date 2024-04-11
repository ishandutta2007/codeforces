#include<cstdio>

int n, m, a[111], x, y;
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", a+i);
    scanf("%d", &m);
    for (;m--;) {
	scanf("%d%d", &x, &y);
	a[x-1]+=y-1; a[x+1]+=a[x]-y; a[x]=0;
    }
    for (int i=1; i<=n; i++) printf("%d\n", a[i]);
    return 0;
}