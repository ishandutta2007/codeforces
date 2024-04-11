#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;
    scanf("%i %i",&n,&d);
    int niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    sort(niz,niz+n);
    int broj=2;
    for(int i=1;i<n;i++)
    {
        int dist=niz[i]-niz[i-1];
        if(dist==2*d)
        {
            broj++;
        }
        if(dist>2*d)
        {
            broj+=2;
        }
    }
    printf("%i\n",broj);
    return 0;
}