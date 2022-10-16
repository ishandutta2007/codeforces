#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    ll n;
    scanf("%lld",&n);
    int sum=0;
    while(n>9)
    {
        //printf("%lld\n",n);
        int r=n%10;
        if(r==9)
        {
            sum+=r;
            n/=10;
        }
        else
        {
            r+=10;
            sum+=r;
            n/=10;
            n--;
        }
    }
    sum+=n;
    printf("%i\n",sum);
    return 0;
}