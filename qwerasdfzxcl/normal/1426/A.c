#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++)
    {
        int n, x;
        scanf("%d %d", &n, &x);
        if (n<=2)
            printf("1\n");
        else
            printf("%d\n", (n-3)/x+2);
    }
    return 0;
}