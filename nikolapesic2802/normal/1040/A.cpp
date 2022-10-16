#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    scanf("%i %i %i",&n,&a,&b);
    int niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    int cost=0;
    for(int i=0;i<n/2;i++)
    {
        //printf("Usao!\n");
        if(niz[i]==2)
        {
            if(niz[n-i-1]==0)
            {
                cost+=a;
            }
            if(niz[n-i-1]==1)
            {
                cost+=b;
            }
            if(niz[n-i-1]==2)
            {
                cost+=2*min(a,b);
            }
        }
        if(niz[i]==1)
        {
            if(niz[n-i-1]==0)
            {
                printf("-1\n");
                return 0;
            }
            if(niz[n-i-1]==2)
            {
                cost+=b;
            }
        }
        if(niz[i]==0)
        {
            if(niz[n-i-1]==1)
            {
                printf("-1\n");
                return 0;
            }
            if(niz[n-i-1]==2)
            {
                //printf("DFa\n");
                cost+=a;
            }
        }
    }
    if(n%2==1&&niz[n/2]==2)
    {
        cost+=min(a,b);
    }
    printf("%i\n",cost);
    return 0;
}