#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

int a;

int ile[5];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &a);
        ile[a&1]++;
    }
    if (n==k)
    {
        if (!(ile[1]&1))
        printf("Daenerys");
        else
        printf("Stannis");
        return 0;
    }
    k=n-k;
    if (!ile[0])
    {
        if (!(k&1))
        {
            printf("Daenerys");
        }
        else
        {
            printf("Stannis");
        }
        return 0;
    }
    if (!ile[1])
    {
        printf("Daenerys");
        return 0;
    }
    if (ile[1]<=(k/2))
    {
        printf("Daenerys");
        return 0;
    }
    if (k&1)
    {
        if (ile[0]<=(k/2)+1 && ((n-k)&1))
        {
            printf("Stannis");
            return 0;
        }
        if (ile[0]<=(k/2) && !((n-k)&1))
        {
            printf("Daenerys");
            return 0;
        }
        if (ile[0]==(k/2)+1 && !((n-k)&1) && ile[1]==(k/2)+1)
        {
            printf("Daenerys");
            return 0;
        }
        printf("Stannis");
    }
    else
    {
        if (ile[0]<=(k/2) && ((n-k)&1))
        {
            printf("Stannis");
            return 0;
        }
        if (ile[0]<=(k/2) && !((n-k)&1))
        {
            printf("Daenerys");
            return 0;
        }
        printf("Daenerys");
        return 0;
    }
    return 0;
}