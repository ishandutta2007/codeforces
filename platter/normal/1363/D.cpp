#include <bits/stdc++.h>
using namespace std;

int group[1001];
int mx;

int solve(int l,int r) {
    if (l==r) {
        return l;
    }
    int mid=(l+r)/2;
    printf("? %d ",mid-l+1);
    for(int i=l;i<=mid;i++) {
        printf("%d ",i);
    }
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    if (x==mx) {
        return solve(l,mid);
    }
    else {
        return solve(mid+1,r);
    }
}

char temp[20];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        memset(group,-1,sizeof(group));
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0;i<k;i++) {
            int x;
            scanf("%d",&x);
            for(int j=0;j<x;j++) {
                int num;
                scanf("%d",&num);
                group[num]=i;
            }
        }
        printf("? %d ",n);
        for(int i=1;i<=n;i++) {
            printf("%d ",i);
        }
        printf("\n");
        fflush(stdout);
        scanf("%d",&mx);
        int pos=solve(1,n);
        int cnt=0;
        for(int i=1;i<=n;i++) {
            if (group[i]!=group[pos]) {
                cnt++;
            }
        }
        printf("? %d ",cnt);
        for(int i=1;i<=n;i++) {
            if (group[i]!=group[pos]) {
                printf("%d ",i);
            }
        }
        printf("\n");
        fflush(stdout);
        int x;
        scanf("%d",&x);
        printf("! ");
        for(int i=0;i<k;i++) {
            if (i==group[pos]) {
                printf("%d ",x);
            }
            else {
                printf("%d ",mx);
            }
        }
        printf("\n");
        fflush(stdout);
        scanf("%s",temp);
    }
}