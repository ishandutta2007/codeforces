#include <bits/stdc++.h>
using namespace std;

char a[100001];
char b[100001];
int deg[20][20];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        memset(deg,0,sizeof(deg));
        int n;
        scanf("%d\n",&n);
        scanf("%s\n%s\n",a,b);
        bool flag=true;
        for(int i=0;i<n;i++) {
            if (a[i]>b[i]) {
                flag=false;
                break;
            }
            deg[a[i]-'a'][b[i]-'a']++;
        }
        if (!flag) {
            printf("-1\n");
            continue;
        }
        int ret=0;
        for(int i=0;i<20;i++) {
            for(int j=0;j<i;j++) {
                if (deg[j][i]!=0) {
                    ret++;
                    for(int k=i;k<20;k++) {
                        deg[i][k]+=deg[j][k];
                        deg[j][k]=0;
                    }
                }
            }
        }
        printf("%d\n",ret);
    }
}