#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    if (n==1)
    {
        printf("1\n1");
        return 0;
    }
    if (n==2)
    {
        printf("1\n1");
        return 0;
    }
    if (n==3)
    {
        printf("2\n1 3");
        return 0;
    }
    if (n==4)
    {
        printf("4\n3 1 4 2");
        return 0;
    }
    printf("%d\n", n);
    for (int i=1; i<=n; i+=2)
    {
        printf("%d ", i);
    }
    for (int i=2; i<=n; i+=2)
    {
        printf("%d", i);
        if (i+2<=n)
        printf(" ");
    }
    return 0;
}