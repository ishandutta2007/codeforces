#include <bits/stdc++.h>
using namespace std;

int n, m;

int czy[107];

int k;
int x;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &k);
        while(k--)
        {
            scanf("%d", &x);
            czy[x]=1;
        }
    }
    for (int i=1; i<=m; i++)
    {
        if (!czy[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}