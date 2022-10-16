#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
char mat[502][502];
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf(" %c",&mat[i][j]);
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(mat[i][j]=='S')
            {
                if(mat[i-1][j]=='W')
                {
                    printf("No\n");
                    return 0;
                }
                if(mat[i+1][j]=='W')
                {
                    printf("No\n");
                    return 0;
                }
                if(mat[i][j-1]=='W')
                {
                    printf("No\n");
                    return 0;
                }
                if(mat[i][j+1]=='W')
                {
                    printf("No\n");
                    return 0;
                }
                if(mat[i-1][j]!='S')
                {
                    mat[i-1][j]='D';
                }
                if(mat[i+1][j]!='S')
                {
                    mat[i+1][j]='D';
                }
                if(mat[i][j+1]!='S')
                {
                    mat[i][j+1]='D';
                }
                if(mat[i][j-1]!='S')
                {
                    mat[i][j-1]='D';
                }
            }
        }
    }
    printf("Yes\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            printf("%c",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}