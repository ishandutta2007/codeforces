#include <bits/stdc++.h>
using namespace std;

char str[100001];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d\n",&n,&k);
        scanf("%s\n",str);
        sort(str,str+n);
        if (n==k) {
            printf("%c\n",str[n-1]);
            continue;
        }
        bool flag=true;
        for(int i=0;i<k;i++) {
            if (str[0]!=str[i]) {
                printf("%c\n",str[k-1]);
                flag=false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        if (str[k]==str[n-1]) {
            printf("%c",str[0]);
            for(int i=0;i<(n-k-1)/k+1;i++) {
                printf("%c",str[k]);
            }
            printf("\n");
        }
        else {
            printf("%c",str[0]);
            for(int i=k;i<n;i++) {
                printf("%c",str[i]);
            }
            printf("\n");
        }
    }
}