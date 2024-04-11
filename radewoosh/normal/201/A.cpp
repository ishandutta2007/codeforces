#include <cstdio>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    if (n==1)
    {
        printf("1");
        return 0;
    }
    if (n==2)
    {
        printf("3");
        return 0;
    }
    if (n==3)
    {
        printf("5");
        return 0;
    }
    if (n==4)
    {
        printf("3");
        return 0;
    }
    for (int i=1; i<=1000; i+=2)
    {
        if ((i*i+1)/2>=n)
        {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}