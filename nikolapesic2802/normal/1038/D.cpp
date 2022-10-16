#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ucitaj_niz(n,niz) for(int i=0;i<n;i++)scanf("%lld",&niz[i]);
int main()
{
    int n;
    scanf("%i",&n);
    ll niz[n];
    ucitaj_niz(n,niz);
    int pocetak=-1;
    for(int i=0;i<n-1;i++)
    {
        if(niz[i]*niz[i+1]<=0)
        {
            pocetak=i;
        }
    }
    if(pocetak==-1)
    {
        int minn=1000000007;
        for(int i=0;i<n;i++)
        {
            if(abs(niz[i])<abs(minn))
            {
                minn=niz[i];
                pocetak=i;
            }
        }
    }
    //printf("%i\n",pocetak);
    ll tr=niz[pocetak];
    for(int i=pocetak+1; i<n-1; i++)
    {
        if(tr*niz[i]>=0)
        {
            tr=abs(tr-niz[i]);
        }
        else
        {
            tr=abs(-1LL*tr+niz[i]);
        }
        if(niz[i+1]>=0)
        {
            tr*=-1;
        }
    }
    //printf("%lld\n",tr);
    if(n>1&&pocetak!=n-1)
    {
        if(tr*niz[n-1]>=0)
        {
            tr=abs(tr-niz[n-1]);
        }
        else
        {
            tr=abs(-1LL*tr+niz[n-1]);
        }
        if(pocetak!=0)
        {
            if(niz[pocetak-1]>=0)
            {
                tr*=-1;
            }
        }
    }
    for(int i=pocetak-1;i>0;i--)
    {
        if(tr*niz[i]>=0)
        {
            tr=abs(tr-niz[i]);
        }
        else
        {
            tr=abs(-1LL*tr+niz[i]);
        }
        if(niz[i-1]>=0)
        {
            tr*=-1;
        }
    }
    if(n>1&&pocetak!=0)
    {
        if(tr*niz[0]>=0)
        {
            tr=abs(tr-niz[0]);
        }
        else
        {
            tr=abs(-1LL*tr+niz[0]);
        }
    }
    printf("%lld\n",tr);
    return 0;
}