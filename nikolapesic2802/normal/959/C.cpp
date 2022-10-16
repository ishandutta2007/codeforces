#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    if(n<6)
    {
        printf("-1\n");
    }
    else
    {
        if(n%2==0)
        {
            printf("1 2\n2 3\n2 6\n3 4\n3 5\n");
            if(n>6)
            {
                printf("5 7\n");
            for(int i=8;i<=n;i++)
            {
                printf("%i %i\n",i-1,i);
            }
            }
        }
        else
        {
            printf("1 2\n1 3\n1 4\n2 7\n2 6\n2 5\n");
            if(n>7)
            {
                printf("5 8\n");
            for(int i=9;i<=n;i++)
            {
                printf("%i %i\n",i-1,i);
            }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        printf("%i %i\n",i,i+1);
    }
    return 0;
}