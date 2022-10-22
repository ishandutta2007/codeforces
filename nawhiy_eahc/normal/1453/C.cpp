#include <iostream>

using namespace std;
int v[2002][2002];
int minx[10], miny[10], maxx[10], maxy[10];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=0;i<10;i++){
            minx[i] = miny[i] = 3000;
            maxx[i] = maxy[i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%1d", &v[i][j]);
                miny[v[i][j]] = min(i, miny[v[i][j]]);
                maxy[v[i][j]] = i;
                minx[v[i][j]] = min(j, minx[v[i][j]]);
                maxx[v[i][j]] = max(j, maxx[v[i][j]]);
            }
        }

        for(int i=0;i<10;i++){
            int result = 0;
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(v[j][k] == i){
                        result = max(result, max(j-1, n-j) * max(k-minx[i], maxx[i]-k));
                        result = max(result, max(k-1, n-k) * max(j-miny[i], maxy[i]-j));
                    }
                }
            }
            printf("%d ", result);
        }
        printf("\n");
    }
}