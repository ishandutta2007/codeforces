#include <bits/stdc++.h>
using namespace std;

char str[50001];
char a[50001];
char b[50001];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        scanf("%s",str);
        for(int i=0;i<n;i++) {
            if (str[i]=='1') {
                a[i]='1';
                b[i]='0';
                for(int j=i+1;j<n;j++) {
                    a[j]='0';
                    b[j]=str[j];
                }
                a[n]=0;
                b[n]=0;
                printf("%s\n%s\n",a,b);
                break;
            }
            else {
                if (str[i]=='0') {
                    a[i]='0';
                    b[i]='0';
                }
                else {
                    a[i]='1';
                    b[i]='1';
                }
            }
            if (i==n-1) {
                a[n]=0;
                b[n]=0;
                printf("%s\n%s\n",a,b);
            }
        }
    }
}