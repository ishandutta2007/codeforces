#include <bits/stdc++.h>
using namespace std;

int n, t;

int main()
{
    scanf("%d%d", &n, &t);
    if (t<10)
    {
        for (int i=1; i<=n; i++)
        {
            printf("%d", t);
        }
    }
    else
    {
        if (n==1)
        {
            printf("-1");
            return 0;
        }
        printf("1");
        for (int i=1; i<n; i++)
        {
            printf("0");
        }
    }
    return 0;
}