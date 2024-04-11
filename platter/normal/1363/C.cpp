#include <bits/stdc++.h>
using namespace std;

int deg[1000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        memset(deg,0,sizeof(deg));
        int n,x;
        scanf("%d %d",&n,&x);
        x--;
        for(int i=1;i<n;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            u--;
            v--;
            deg[u]++;
            deg[v]++;
        }
        if (deg[x]<=1) {
            printf("Ayush\n");
            continue;
        }
        printf("%s\n",(n-3)%2==1?"Ayush":"Ashish");
    }
}