#include <bits/stdc++.h>

using namespace std;
int x[250001]={0};
int y[250001]={0};
int ans[501][501]={0};

int main()
{
    int t;
    scanf("%d", &t);
    for (int z=0;z<t;z++){
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i=0;i<n*m;i++){
            x[i]=0;
            y[i]=0;
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int tmp;
                scanf("%d", &tmp);
                x[tmp]=j;
            }
        }
        for (int j=0;j<m;j++){
            for (int i=0;i<n;i++){
                int tmp;
                scanf("%d", &tmp);
                y[tmp]=i;
            }
        }
        for (int i=1;i<=m*n;i++){
            ans[x[i]][y[i]]=i;
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) printf("%d ", ans[j][i]);
            printf("\n");
        }
    }
    return 0;
}