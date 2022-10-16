#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,d;
    scanf("%i %i",&n,&d);
    int x=d;
    int poz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&poz[i]);
    }
    int p[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&p[i]);
    }
    int maxx=poz[d-1]+p[0];
    //printf("%i\n",maxx);
    int tr=n-1;
    //printf("%i\n",p[tr]);
    for(int i=0;i<x-1;i++)
    {
        //printf("Min za %i: %i\n",i,poz[i]+p[tr]);
        if(poz[i]+p[tr]<=maxx)
        {
            d--;
            tr--;
        }
    }
    printf("%i\n",d);
    return 0;
}