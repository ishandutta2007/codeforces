#include <bits/stdc++.h>
using namespace std;

char str[1001];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%s\n",str);
        int n=strlen(str);
        int ret=n;
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=str[i]-'0';
        }
        ret=min(ret,sum);
        for(int i=0;i<n;i++) {
            if (str[i]=='1') {
                sum--;
            }
            else {
                sum++;
            }
            ret=min(ret,sum);
        }
        sum=0;
        for(int i=0;i<n;i++) {
            sum+='1'-str[i];
        }
        for(int i=0;i<n;i++) {
            if (str[i]=='0') {
                sum--;
            }
            else {
                sum++;
            }
            ret=min(ret,sum);
        }
        printf("%d\n",ret);
    }
}