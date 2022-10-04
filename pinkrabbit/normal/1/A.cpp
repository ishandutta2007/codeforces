#include<cstdio>
int main(){
    int m, n, a;
    scanf("%d%d%d", &m, &n, &a);
    printf("%I64d", (long long)((m - 1)/ a + 1) * ((n - 1)/ a + 1));
    return 0;
}