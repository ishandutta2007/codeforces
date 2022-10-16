#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,s;
    scanf("%i %i",&n,&s);
    int niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    sort(niz,niz+n);
    if(niz[n/2]==s)
    {
        printf("0\n");
        return 0;
    }
    long long res=0;
    if(niz[n/2]>s)
    {

        for(int i=0;i<=n/2;i++)
        {
            res+=max(0,niz[i]-s);
        }
    }
    else
    {
        for(int i=n/2;i<n;i++)
        {
            res+=max(0,s-niz[i]);
        }
    }
    printf("%I64d\n",res);
    return 0;
}