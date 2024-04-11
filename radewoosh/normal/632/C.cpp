#include <bits/stdc++.h>
using namespace std;

int n;

char wcz[100007][57];

int dlu[100007];

int dos[100007];

char jed[107];
char dwa[107];

bool mniej(int a, int b)
{
    int d=dlu[a]+dlu[b];
    for (int i=0; i<d; i++)
    {
        if (i<dlu[a])
        jed[i]=wcz[a][i];
        else
        jed[i]=wcz[b][i-dlu[a]];

        if (i<dlu[b])
        dwa[i]=wcz[b][i];
        else
        dwa[i]=wcz[a][i-dlu[b]];
    }
    for (int i=0; i<d; i++)
    {
        if (jed[i]!=dwa[i])
        return jed[i]<dwa[i];
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", wcz[i]);
        for (int j=0; 1; j++)
        {
            if (!wcz[i][j])
            {
                dlu[i]=j;
                break;
            }
        }
        dos[i]=i;
    }
    sort(dos+1, dos+1+n, mniej);
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<dlu[dos[i]]; j++)
        {
            printf("%c", wcz[dos[i]][j]);
        }
    }
    printf("\n");
    return 0;
}