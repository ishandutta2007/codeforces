#include <bits/stdc++.h>
using namespace std;

int arr[200000];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%d ",&arr[i]);
        }
        bool allsame=true;
        for(int i=0;i<n;i++) {
            if (arr[i]!=arr[(i+1)%n]) {
                allsame=false;
            }
        }
        if (allsame) {
            printf("1\n");
            for(int i=0;i<n;i++) {
                printf("1 ");
            }
            printf("\n");
            continue;
        }
        if (n%2==0) {
            printf("2\n");
            for(int i=0;i<n;i++) {
                printf("%d ",i%2+1);
            }
            printf("\n");
            continue;
        }
        bool same=false;
        int pos=-1;
        for(int i=0;i<n;i++) {
            if (arr[i]==arr[(i+1)%n]) {
                same=true;
                pos=i;
            }
        }
        if (!same) {
            printf("3\n");
            for(int i=0;i<n;i++) {
                if (i==n-1) {
                    printf("3\n");
                }
                else {
                    printf("%d ",i%2+1);
                }
            }
        }
        else {
            printf("2\n");
            int cnt=1;
            bool ch=false;
            for(int i=0;i<n;i++) {
                printf("%d ",cnt);
                if (arr[i]==arr[(i+1)%n]&&(!ch)) {
                    ch=true;
                }
                else {
                    cnt=3-cnt;
                }
            }
            printf("\n");
        }
    }
}