#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mod[111];
    int n,k; cin>>n>>k;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    memset(mod,0,sizeof mod);
    for(int i=0;i<n;i++)
    {
        mod[a[i]%k]++;
    }

    long long int res=0;
    res+=mod[0]/2*2;
    for(int i=1;i<=k/2;i++)
    {
        if(i*2==k) res+=mod[i]/2*2;
        else
        {
            res+=min(mod[i],mod[k-i])*2;
        }
    }
    cout<<res;
    return 0;
}