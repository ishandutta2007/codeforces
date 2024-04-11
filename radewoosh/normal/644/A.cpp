#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int x;

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    if (n>a*b)
    {
        printf("-1\n");
        return 0;
    }
    for (int i=1; i<=a; i++)
    {
        if (i&1)
        {
            for (int j=1; j<=b; j++)
            {
                x=(i-1)*b+j;
                if (x>n)
                x=0;
                printf("%d ", x);
            }
        }
        else
        {
            for (int j=b; j; j--)
            {
                x=(i-1)*b+j;
                if (x>n)
                x=0;
                printf("%d ", x);
            }
        }
        printf("\n");
    }
    return 0;
}