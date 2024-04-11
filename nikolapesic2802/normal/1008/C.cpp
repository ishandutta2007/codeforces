#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int abv[n],niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&abv[i]);
    }
    sort(abv,abv+n);
    for(int i=0;i<n;i++)
    {
        niz[i]=abv[n-i-1];
        //printf("%i ",niz[i]);
    }
    int p1=0;
    for(int i=1;i<n;i++)
    {
        if(niz[i]<niz[p1])
        {
            p1++;
        }
    }
    printf("%i\n",p1);
    return 0;
}