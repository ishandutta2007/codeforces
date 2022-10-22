#include <bits/stdc++.h>
using namespace std;

int julde(int x) {
    return x>0?x:-x;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;

bool valid(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<m;
}
int cnt[300][300];

int main(void) {
    int tc;
    scanf("%d",&tc);
    int arr[300][300];
    for(int t=0;t<tc;t++) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cnt[i][j]=0;
                scanf("%d",&arr[i][j]);
                for(int k=0;k<4;k++) {
                    if (valid(i+dx[k],j+dy[k])) {
                        cnt[i][j]++;
                    }
                }
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (arr[i][j]>cnt[i][j]) {
                    flag=false;
                }
            }
        }
        if (!flag) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                printf("%d ",cnt[i][j]);
            }
            printf("\n");
        }
    }
}