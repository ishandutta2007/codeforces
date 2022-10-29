#include "bits/stdc++.h"
using namespace std;
#define N (int)1e5+9
long long i,a[N],n,k,sum,b[N];
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    if(a[n]%k)
    {
        cout<<"No";
        return 0;
    }
    sum=a[n]/k;
    long long pos=0,j=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]-a[pos]==sum)
        {
            b[j++]=i-pos;
            pos=i;
        }
        if(a[i]-a[pos]>sum)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes\n";
    for(i=0;i<j;i++)
    {
        cout<<b[i]<<' ';
    }
}