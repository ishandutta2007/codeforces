#include <bits/stdc++.h>
using namespace std;

char str[300001];
bool o[300001];
bool tw[300001];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d\n",&n,&k);
        for(int i=0;i<n;i++) {
            scanf("%c",&str[i]);
            o[i]=false;
            tw[i]=false;
        }
        scanf("\n");
        for(int i=0;i<n;i++) {
            if (str[i]=='0') {
                o[i%k]=true;
            }
            if (str[i]=='1') {
                tw[i%k]=true;
            }
        }
        for(int i=0;i<k;i++) {
            if (o[i]) {
                str[i]='0';
            }
            if (tw[i]) {
                str[i]='1';
            }
        }
        int one=0;
        int two=0;
        bool flag=true;
        for(int i=0;i<k;i++) {
            if (str[i]=='0') {
                one++;
            }
            if (str[i]=='1') {
                two++;
            }
        }
        if (one>k/2||two>k/2) {
            flag=false;
        }
        for(int i=0;i<k;i++) {
            if (o[i]&&tw[i]) {
                flag=false;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
}