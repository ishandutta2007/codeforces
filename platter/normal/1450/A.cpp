#include <bits/stdc++.h>
using namespace std;

int n;
char str[2001];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%c",&str[i]);
        }
        sort(str,str+n);
        for(int i=0;i<n;i++) {
            printf("%c",str[i]);
        }
        printf("\n");
    }
}