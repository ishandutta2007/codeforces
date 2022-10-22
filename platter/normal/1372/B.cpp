#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        bool flag=false;
        for(int i=2;i*i<=n;i++) {
            if (n%i==0) {
                printf("%d %d\n",n/i,(n/i)*(i-1));
                flag=true;
                break;
            }
        }
        if (!flag) {
            printf("%d %d\n",1,n-1);
        }
    }
}