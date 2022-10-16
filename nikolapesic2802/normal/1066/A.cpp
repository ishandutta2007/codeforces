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
        int L,v,l,r;
        scanf("%i %i %i %i",&L,&v,&l,&r);
        int d=(l-1)/v;
        int lo=r/v;
        printf("%i\n",L/v-lo+d);
    }
    return 0;
}