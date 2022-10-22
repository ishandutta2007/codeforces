#include <bits/stdc++.h>
using namespace std;
 
int a[100000];
int b[100000];
 
int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        int st=0;
        int dir=1;
        int flip=0;
        for(int i=0;i<n;i++) {
            scanf("%1d",&a[i]);
        }
        for(int i=0;i<n;i++) {
            scanf("%1d",&b[i]);
        }
        vector<int> ret;
        for(int i=n-1;i>=0;i--) {
            if ((a[st]^flip)==b[i]) {
                ret.push_back(1);
                a[st]^=1;
            }
            ret.push_back(i+1);
            flip^=1;
            st=st+dir*i;
            dir=-dir;
        }
        printf("%d ",ret.size());
        for(int i=0;i<ret.size();i++) {
            printf("%d ",ret[i]);
        }
        printf("\n");
    }
}