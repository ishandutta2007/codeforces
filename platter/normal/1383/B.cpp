#include <bits/stdc++.h>
using namespace std;

int arr[100000];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        int flag=0;
        for(int bit=29;bit>=0;bit--) {
            int cnt=0;
            for(int i=0;i<n;i++) {
                if (arr[i]&(1<<bit)) {
                    cnt++;
                }
            }
            if (cnt%2==1) {
                if (cnt%4==1) {
                    flag=1;
                }
                if (cnt%4==3) {
                    if ((n-cnt)%2==1) {
                        flag=1;
                    }
                    else {
                        flag=-1;
                    }
                }
                break;
            }
        }
        printf("%s\n",flag>=0?(flag==1?"WIN":"DRAW"):"LOSE");
    }
}