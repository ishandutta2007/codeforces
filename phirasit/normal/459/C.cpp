#include <stdio.h>

#define N 1010

int out[N][N];

int arr[N];
int n, d, k;
int cnt = 0;
bool err = false;

void dfs(int id) {
    if(id >= d) {
        for(int i = 0;i < d;i++) {
            out[i][cnt] = arr[i];
        }
        cnt++;
        return;
    }
    for(int i = 1;i <= k;i++) {
        if(cnt >= n) {
            return;
        }
        arr[id] = i;
        dfs(id+1);
    }
    if(id == 0 && cnt < n) {
        err = true;
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &d);
    dfs(0);
    if(err) {
        printf("-1\n");
    }else {
        for(int i = 0;i < d;i++) {
            for(int j = 0;j < n;j++) {
                printf("%d ", out[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}