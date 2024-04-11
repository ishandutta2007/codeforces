#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d",&n,&k);
        set<int> s;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        if (k==1) {
            if (s.size()==1) {
                printf("1\n");
            }
            else {
                printf("-1\n");
            }
            continue;
        }
        if (s.size()==1) {
            printf("1\n");
            continue;
        }
        printf("%d\n",(s.size()-2)/(k-1)+1);
    }
}