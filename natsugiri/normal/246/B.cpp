#include<cstdio>

int n, s, t;
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
	scanf("%d", &t);
	s+=t;
    }
    printf("%d\n", s%n==0?n:n-1);
    return 0;
}