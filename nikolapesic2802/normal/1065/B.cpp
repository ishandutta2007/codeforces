#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n;
    ll m;
    scanf("%i %lld",&n,&m);
    if(n==1)
    {
        printf("1 1\n");
        return 0;
    }
    ll mid=(ll)n-(ll)m*2;
    mid=max(mid,(ll)0);
    ll maxx=n+1;
    for(int i=1;i<=n;i++)
    {
        ll tr=(ll)i*(ll)(i-1)/2;
        if(tr<m)
        {
            maxx=n-i;
        }
    }
    maxx--;
    maxx=max(maxx,(ll)0);
    printf("%lld %lld\n",mid,maxx);
    return 0;
}