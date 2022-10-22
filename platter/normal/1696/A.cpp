#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,z;
        scanf("%d %d",&n,&z);
        int ret=0;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            ret=max(ret,x|z);
        }
        printf("%d\n",ret);
    }
    return 0;
}