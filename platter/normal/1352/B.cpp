#include <bits/stdc++.h>
using namespace std;
 
char str[6];
int pow10[5]={1,10,100,1000,10000};
 
int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d\n",&n,&k);
        if (n<k||(n%2==1&&k%2==0)||(k%2==1&&n%2==0&&n<2*k)) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int minus=0;
        for(int i=0;i<k-1;i++) {
            printf("%d ",k%2==0?1:(n%2==0?2:1));
            if (k%2==1&&n%2==0) {
                minus+=2;
            }
            else {
                minus++;
            }
        }
        printf("%d\n",n-minus);
    }
}