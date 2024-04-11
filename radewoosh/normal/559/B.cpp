#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

char wcz1[200007];
char wcz2[200007];

int rek(int l, int p)
{
    if ((l+p)&1)
    {
        rek(l, (l+p)>>1);
        rek((l+p+2)>>1, p);
        int s=(l+p+2)>>1;
        for (int i=0; i+l<s; i++)
        {
            if (wcz1[l+i]>wcz1[s+i])
            {
                for (int j=0; j+l<s; j++)
                {
                    swap(wcz1[l+j], wcz1[s+j]);
                }
                break;
            }
            if (wcz1[l+i]<wcz1[s+i])
            {
                break;
            }
        }
        for (int i=0; i+l<s; i++)
        {
            if (wcz2[l+i]>wcz2[s+i])
            {
                for (int j=0; j+l<s; j++)
                {
                    swap(wcz2[l+j], wcz2[s+j]);
                }
                break;
            }
            if (wcz2[l+i]<wcz2[s+i])
            {
                break;
            }
        }
    }
    for (int i=l; i<=p; i++)
    if (wcz1[i]!=wcz2[i])
    return 0;
    return 1;
}

int main()
{
    scanf("%s%s", wcz1, wcz2);
    for (int i=1; 1; i++)
    {
        if (!wcz1[i])
        {
            n=i;
            break;
        }
    }
    if (rek(0, n-1))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}