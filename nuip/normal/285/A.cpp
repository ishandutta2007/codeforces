#include <cstdio>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++)
        printf("%d ", (i<k)?n-i:i-k+1);
    printf("\n");
    return 0;
}