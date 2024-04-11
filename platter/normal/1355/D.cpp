#include <bits/stdc++.h>
using namespace std;

int arr[200000];

int main(void) {
    int n,s;
    scanf("%d %d\n",&n,&s);
    if (s>=2*n) {
        printf("YES\n");
        for(int i=0;i<n-1;i++) {
            printf("2 ");
        }
        printf("%d\n",s-2*n+2);
        printf("1\n");
        return 0;
    }
    printf("NO");
}