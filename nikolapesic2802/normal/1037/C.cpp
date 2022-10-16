#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    char niz1[n+1],niz2[n+1];
    scanf("%s %s",niz1,niz2);
    int cost=0;
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            if(niz1[i]!=niz1[i+1])
            {
                if(niz1[i]!=niz2[i]&&niz1[i+1]!=niz2[i+1])
                {
                    cost++;
                    i++;
                    continue;
                }
            }
        }
        if(niz1[i]!=niz2[i])
        cost++;
    }
    printf("%i",cost);
    return 0;
}