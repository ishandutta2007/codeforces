#include <stdio.h>

int tile[100][4];

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++)
    {
        int n, m, test=0;
        scanf("%d %d", &n, &m);
        for (int j=0;j<n;j++)
        {
            scanf("%d %d", &tile[j][0], &tile[j][1]);
            scanf("%d %d", &tile[j][2], &tile[j][3]);
            if (tile[j][1]==tile[j][2])
                test=1;
        }
        if (m%2==1)
            printf("NO\n");
        else
        {
            if (test==0)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}