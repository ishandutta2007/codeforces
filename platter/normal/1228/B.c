#include <stdio.h>

int main(void) {
    int h,w;
    scanf("%d %d\n", &h, &w);
    int he[1000];
    int we[1000];
    int grid[1000][1000];
    for(int i=0;i<1000;i++) {
        for(int j=0;j<1000;j++) {
            grid[i][j]=0;
        }
    }
    for(int i=0;i<h;i++) {
        scanf("%d ", &he[i]);
    }
    scanf("\n");
    for(int i=0;i<w;i++) {
        scanf("%d ", &we[i]);
    }
    for(int i=0;i<h;i++) {
        for(int j=0;j<he[i];j++) {
            grid[i][j]=1;
        }
        grid[i][he[i]]=-1;
    }
    for(int i=0;i<w;i++) {
        for(int j=0;j<we[i];j++) {
            if (grid[j][i]==-1) {
                printf("0");
                return 0;
            }
            grid[j][i]=1;
        }
        if (grid[we[i]][i]==1) {
            printf("0");
            return 0;
        }
        grid[we[i]][i]=-1;
    }
    int to=0;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if (grid[i][j]==0) {
                to+=1;
            }
        }
    }
    int ans=1;
    for(int i=0;i<to;i++) {
        ans=(ans*2)%1000000007;
    }
    printf("%d", ans);
    return 0;
}