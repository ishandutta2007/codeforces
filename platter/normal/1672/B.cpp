#include <bits/stdc++.h>
using namespace std;

char str[200001];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%s",str);
        int n=strlen(str);
        bool flag=true;
        if (str[0]=='B'||str[n-1]=='A') {
            flag=false;
        }
        int val=0;
        for(int i=0;i<n;i++) {
            if (str[i]=='A') {
                val++;
            }
            else {
                val--;
            }
            if (val<0) {
                flag=false;
            }
        }
        printf("%s\n",flag?"Yes":"No");
    }
}