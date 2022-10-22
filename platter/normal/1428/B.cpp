#include <bits/stdc++.h>
using namespace std;

char str[300001];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        scanf("%s\n",str);
        bool flag1=true;
        bool flag2=true;
        for(int i=0;i<n;i++) {
            if (str[i]=='<') {
                flag1=false;
            }
            if (str[i]=='>') {
                flag2=false;
            }
        }
        if (flag1||flag2) {
            printf("%d\n",n);
            continue;
        }
        int ret=0;
        for(int i=0;i<n;i++) {
            if (str[i]=='-'||str[(i+n-1)%n]=='-') {
                ret++;
            }
        }
        printf("%d\n",ret);
    }
}