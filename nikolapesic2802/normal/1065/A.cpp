#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int t;
    scanf("%i",&t);
    while(t--)
    {
        int s,a,b,c;
        scanf("%i %i %i %i",&s,&a,&b,&c);
        int broj=s/c;
        int koliko=broj/a;
        ll res=broj+(ll)koliko*b;
        printf("%lld\n",res);
    }
    return 0;
}