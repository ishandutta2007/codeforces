#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int dx[2] = {0, 1}, dy[2] = {-1, 0};
int ans[505][505];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) ans[i][j] = -1;
    }
    for (int i=0;i<n;i++) scanf("%d", &ans[i][i]);
    for (int i=0;i<n;i++){
        int cnt = ans[i][i]-1;
        int curx = i, cury = i;
        while(cnt>0){
            //printf("YES\n");
            for (int k=0;k<2;k++) if (cury+dy[k]>=0 && ans[curx+dx[k]][cury+dy[k]]==-1){
                ans[curx+dx[k]][cury+dy[k]] = ans[i][i];
                curx += dx[k]; cury += dy[k];
                break;
            }
            cnt--;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            assert(ans[i][j]!=-1);
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}