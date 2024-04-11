#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        int a[1000000];
        int b[1000000];
        for(int i=0;i<n;i++) {
            scanf("%d ", &a[i]);
        }
        scanf("\n");
        for(int i=0;i<n;i++) {
            scanf("%d ", &b[i]);
        }
        scanf("\n");
        bool ans=true;
        int diff=0;
        bool check=false;
        for(int i=0;i<n;i++) {
            if (check) {
                if (b[i]==a[i]) {
                    bool temp=true;
                    for(int j=i+1;j<n;j++) {
                        if (a[j]!=b[j]) {
                            temp=false;
                        }
                    }
                    if (temp) {
                        ans=true;
                    }
                    else {
                        ans=false;
                    }
                    break;
                }
                if (b[i]-a[i]!=diff) {
                    ans=false;
                    break;
                }
            }
            else {
                if (a[i]!=b[i]) {
                    check=true;
                    diff=b[i]-a[i];
                    if (diff<0) {
                        ans=false;
                        break;
                    }
                }
            }
        }
        if (ans) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}