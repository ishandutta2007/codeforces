#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%i %i %i",&n,&m,&k);
    int n1=n,m1=m;
    if(((long long)n*m*2LL)%(long long)k!=0)
    {
        printf("NO\n");
        return 0;
    }
    bool resen=false;
    if(k%2==0)
    {
        k/=2;
        resen=true;
    }
    for(int i=2;i<=sqrt(k);i++)
    {
        while(k%i==0)
        {
            k/=i;
            if(n%i==0)
            {
                n/=i;
            }
            else
            {
                if(m%i!=0)
                {
                    printf("wtf\n");
                }
                m/=i;
            }
        }
    }
    if(k!=1)
    {
        if(n%k==0)
        {
            n/=k;
        }
        else
            {
                if(m%k!=0)
                {
                    printf("wtf\n");
                }
                m/=k;
            }
    }
    if(!resen)
    {
        if(n*2<=n1)
        {
            n*=2;
        }
        else
        {
            m*=2;
        }
    }
    printf("YES\n0 0\n%i 0\n0 %i\n",n,m);
    return 0;
}