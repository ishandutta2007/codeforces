#include <bits/stdc++.h>
using namespace std;

char wcz[1007];
int l;

int wyn;

int main()
{
    scanf("%s", wcz+1);
    for (int i=1; wcz[i]; i++)
    {
        l=1;
        for (int j=i+1; wcz[j]; j++)
        {
            if (wcz[j]==wcz[i] && !((i+j+l)&1))
            {
                l++;
            }
        }
        wyn=max(wyn, l);
    }
    printf("%d\n", wyn);
    return 0;
}