#include <bits/stdc++.h>

using namespace std;

long long bit[32];
long long pot[32];

int main()
{
    pot[0]=1;
    for(int i=1;i<32;i++)
    {
        pot[i]=pot[i-1]*2;
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,a,res=0;
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>a;
        long long it=0;
        while(a>=1)
        {
            if(a%2) bit[it]++;
            a/=2;
            it++;
        }
    }
    for(long long i=0;i<n;i++)
    {
        long long x=0;
        for(long long j=0;j<32;j++)
        {
            if(bit[j]>0)
            {
                x+=pot[j];
                bit[j]--;
            }
        }
        res+=x*x;
    }
    cout<<res;

    return 0;
}