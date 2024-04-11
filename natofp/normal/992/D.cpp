#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long int INF=3e18;

int main()
{
    long long int n,k; cin>>n>>k;
    long long int * a=new long long int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int * pop=new int[n];
    pop[0]=-1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==1)
        {
            if(a[i-1]==1) pop[i]=pop[i-1];
            else pop[i]=i-1;
        }
    }
    long long int res=0;
    long long int sum;
    long long int ilo;
    for(int i=0;i<n;i++)
    {
        sum=0;
        ilo=1;
        for(int j=i;j>=0;j--)
        {
            if(a[j]!=1)
            {
                if(INF/a[j]<ilo) break;
                sum+=a[j];
                ilo*=a[j];
                if(sum*k==ilo) res++;
            }
            else
            {
                int t=pop[j];
                long long ile=(long long int)j-t;
                if(ilo%k==0)
                {
                    long long wyn=ilo/k;
                    if(sum<wyn && sum+ile>=wyn) res++;
                }
                sum+=ile;
                j=pop[j];
                j++;
            }
        }
    }
    cout<<res;
    return 0;
}