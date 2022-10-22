#include <bits/stdc++.h>
using namespace std;

char s[501];
char t[1001];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int te=0;te<tc;te++) {
        scanf("%s %s",s,t);
        int n=strlen(s);
        int m=strlen(t);
        bool f=false;
        for(int i=0;i<n;i++) {
            if (f) {
                break;
            }
            for(int j=0;j<m;j++) {
                bool flag=true;
                flag=true;
                for(int k=0;k<m;k++) {
                    int diff=abs(k-j);
                    int pos=i-diff;
                    if (pos<0||pos>=n) {
                        flag=false;
                        break;
                    }
                    if (s[pos]!=t[k]) {
                        flag=false;
                        break;
                    }
                }
                if (flag) {
                    f=true;
                    //printf("%d %d\n",i,j);
                    break;
                }
            }
        }
        printf("%s\n",f?"YES":"NO");
    }
    return 0;
}