#include <bits/stdc++.h>
using namespace std;

char str[101];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%s\n",str);
        int n=strlen(str);
        bool flag=true;
        for(int i=1;i<n;i++) {
            if (str[i-1]!=str[i]) {
                flag=false;
            }
        }
        if (flag) {
            printf("%s\n",str);
        }
        else {
            for(int i=0;i<n;i++) {
                printf("01");
            }
            printf("\n");
        }
    }
}