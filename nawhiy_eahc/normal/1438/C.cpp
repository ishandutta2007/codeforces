#include <iostream>
#define forn(i, n) for(i=1;i<=n;i++)

using namespace std;
int a[102][102];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d", &a[i][j]);
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i+j)%2 != a[i][j]%2) a[i][j]++;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}