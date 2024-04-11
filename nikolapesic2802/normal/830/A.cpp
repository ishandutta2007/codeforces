#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,k,p;
    scanf("%i %i %i",&n,&k,&p);
    vector<int> niz(n),klucevi(k);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    for(int i=0;i<k;i++)
    {
        scanf("%i",&klucevi[i]);
    }
    sort(niz.begin(),niz.end());
    sort(klucevi.begin(),klucevi.end());
    ll minn=LLONG_MAX;
    for(int i=0;i<=k-n;i++)
    {
        ll dist=0;
        for(int j=0;j<n;j++)
        {
            //printf("Usao za %i  %i\n",niz[j-i],klucevi[j]);
            dist=max(dist,(ll)abs(niz[j]-klucevi[j+i])+abs(klucevi[j+i]-p));
        }
        minn=min(minn,dist);
    }
    printf("%lld\n",minn);
    return 0;
}