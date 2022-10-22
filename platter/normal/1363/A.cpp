#include <bits/stdc++.h>
using namespace std;

int arr[1000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,x;
        scanf("%d %d",&n,&x);
        int odd=0;
        int even=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            if (arr[i]%2==1) {
                odd++;
            }
            else {
                even++;
            }
        }
        bool flag=false;
        for(int i=1;i<=odd;i+=2) {
            if (x-i>=0&&x-i<=even) {
                printf("Yes\n");
                flag=true;
                break;
            }
        }
        if (!flag) {
            printf("No\n");
        }
    }
}