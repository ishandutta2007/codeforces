#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,h[1000001],sum,i;
ll l,r,mid;
ll res[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>h[i];
        sum+=h[i];
    }
    for (i=1;i<=n;i++)
    {
        l=0;r=2e12;
        while(l<r)
        {
            mid=(l+r)/2;
            if (((mid)+(mid+n-i))*(n-i+1)/2>=sum) r=mid; else l=mid+1;
        }
        res[i]=l;
        cout<<res[i]<<' ';
         
        sum-=l;
    }
}