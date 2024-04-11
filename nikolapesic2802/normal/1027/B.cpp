#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    scanf("%i %i",&n,&q);
    long long N=(long long)n*(long long)n;
    long long pola=(N+1)/(long long)2;
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%i %i",&x,&y);
        long long res;
        long long red=n;
        if((x+y)%2==0)
        {
            res=(long long)(x-1)/2*red;
            if(x%2==0)
            {
                res+=(long long)(n+1)/2;
                res+=(long long)(y)/2;
            }
            else
            {
                res+=(long long)(y+1)/2;
            }
        }
        else
        {
            res=pola;
            res+=(long long)(x-1)/2*red;
            if(x%2==0)
            {
                res+=(long long)(n)/2;
                res+=(long long)(y+1)/2;
            }
            else
            {
                res+=(long long)(y)/2;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}