#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int niz[n];
    for(int i=0;i<n;i++)
        scanf("%i",&niz[i]);
    int x,f;
    scanf("%i %i",&x,&f);
    ll cost=0;
    for(int i=0;i<n;i++)
    {
        int broj=((niz[i]-x)/(x+f));
        if((niz[i]-x)%(x+f)!=0&&niz[i]-x>0)
            broj++;
        cost+=(ll)broj;
    }
    printf("%lld\n",cost*(ll)f);
    return 0;
}