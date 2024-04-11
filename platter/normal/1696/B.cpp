#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        bool flag=false;
        int ret=0;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            if (x!=0) {
                if (!flag) {
                    flag=true;
                    ret++;
                }
            }
            else {
                flag=false;
            }
        }
        printf("%d\n",min(ret,2));
    }
    return 0;
}