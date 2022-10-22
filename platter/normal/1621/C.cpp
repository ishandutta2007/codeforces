#include <bits/stdc++.h>
using namespace std;

int nt[10001];

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            nt[i]=-1;
        }
        int cnt=0;
        for(int i=1;i<=n;i++) {
            if (nt[i]!=-1) {
                continue;
            }
            int now;
            int save=0;
            printf("? %d\n",i);
            fflush(stdout);
            scanf("%d",&now);
            int save1=now;
            while (save==0||now!=save1) {
                printf("? %d\n",i);
                fflush(stdout);
                scanf("%d",&nt[now]);
                now=nt[now];
                cnt++;
                save=1;
            }
        }
        printf("! ");
        for(int i=1;i<=n;i++) {
            printf("%d ",nt[i]);
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}