#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
int num[100002];

int main() {
    int n, p1, p2;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d",num+i);
    p1 = 1;
    p2 = n;
    for(int sum1=0,sum2=0;p1<=p2;) {
        if (sum1 <= sum2)
            sum1+=num[p1++];
        else
            sum2+=num[p2--];
    }
    printf("%d %d",p1-1,n-p2);
    return 0;
}