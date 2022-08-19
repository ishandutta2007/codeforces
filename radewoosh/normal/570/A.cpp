#include <bits/stdc++.h>
using namespace std;

int n, m;

int kt;
int bylo;

int tab[107][107];
int x;

int tab2[107];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        kt=0;
        bylo=0;
        for (int j=1; j<=n; j++)
        {
            scanf("%d", &x);
            if (!kt || x>bylo)
            {
                bylo=x;
                kt=j;
            }
        }
        tab2[kt]++;
    }
    kt=0;
    for (int j=1; j<=n; j++)
    {
        if (!kt || tab2[j]>tab2[kt])
        {
            kt=j;
        }
    }
    printf("%d", kt);
    return 0;
}