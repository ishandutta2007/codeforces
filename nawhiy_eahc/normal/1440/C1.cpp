#include <iostream>

using namespace std;
int a[102][102];
int q[6][10002];
int cnt;

void init(int h, int b, int c, int d, int e, int f){
    q[0][cnt] = h;
    q[1][cnt] = b;
    q[2][cnt] = c;
    q[3][cnt] = d;
    q[4][cnt] = e;
    q[5][cnt] = f;
    a[h][b] = !a[h][b];
    a[c][d] = !a[c][d];
    a[e][f] = !a[e][f];
    cnt++;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%1d", &a[i][j]);
            }
        }
        cnt=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m;j++){
                if(a[i][j] == 0 && a[i][j+1] == 0) continue;
                if(a[i][j] == 0){
                    init(i, j+1, i+1, j, i+1, j+1);
                    continue;
                }
                if(a[i][j+1] == 1){
                    init(i, j, i, j+1, i+1, j);
                    continue;
                }
                init(i, j, i+1, j, i+1, j+1);
            }
        }

        for(int j=1;j<m-1;j++){
            if(a[n-1][j] == 0 && a[n][j] == 0) continue;
            if(a[n-1][j] == 0){
                init(n-1, j+1, n, j, n, j+1);
                continue;
            }
            if(a[n][j] == 1){
                init(n-1, j, n-1, j+1, n, j);
                continue;
            }
            init(n-1, j, n-1, j+1, n, j+1);
        }
        here:
        int ab = a[n-1][m-1] + a[n-1][m] + a[n][m-1] + a[n][m];
        int b[4];
        b[0] = a[n-1][m-1], b[1] = a[n-1][m], b[2] = a[n][m-1], b[3] = a[n][m];
        if(ab == 4){
            init(n-1, m-1, n-1, m, n, m-1);
            goto here;
        }
        if(ab == 3){
            if(!b[0])
                init(n-1, m, n, m-1, n, m);
            if(!b[1])
                init(n-1, m-1, n, m-1, n, m);
            if(!b[2])
                init(n-1, m-1, n-1, m, n, m);
            if(!b[3])
                init(n-1, m-1, n-1, m, n, m-1);
        }
        if(ab == 2){
            if(!b[0]){
                if(!b[1] || !b[2]){
                    init(n-1, m-1, n-1, m, n, m-1);
                    goto here;
                }
                init(n-1, m-1, n-1, m, n, m);
                goto here;
            }
            if(b[1]){
                init(n-1, m-1, n, m-1, n, m);
                goto here;
            }
            if(b[2]){
                init(n-1, m-1, n-1, m, n, m);
                goto here;
            }
            init(n-1, m-1, n-1, m, n, m-1);
            goto here;
        }

        if(ab == 1){
            if(b[0]){
                init(n-1, m-1, n-1, m, n, m-1);
                goto here;
            }
            init(n-1, m, n, m-1, n, m);
            goto here;
        }

        printf("%d\n", cnt);
        for(int i=0;i<cnt;i++){
            printf("%d %d %d %d %d %d\n", q[0][i], q[1][i], q[2][i], q[3][i], q[4][i], q[5][i]);
        }
    }
}