#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++)
    {
        int n, x;
        double yay;
        scanf("%d", &n);
        yay=sqrt(n);
        x=yay;
        if (x*x==n)
            printf("%d\n", 2*x-2);
        else if (x*(x+1)>=n)
            printf("%d\n", 2*x-1);
        else
            printf("%d\n", 2*x);
    }
    return 0;
}