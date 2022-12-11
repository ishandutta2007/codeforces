#include <stdio.h>

int main() {
	int n,m,a;
	scanf("%d %d %d",&n,&m,&a);
	printf("%I64d\n",(long long)(n/a + !!(n%a)) * (m/a + !!(m%a)));
	return 0;
}