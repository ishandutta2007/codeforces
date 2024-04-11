#include <bits/stdc++.h>

using namespace std;
long long tab[500007];
long long pref[500007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,n1,x;
    cin>>n;
    n1=n/2+n%2;
    for(long long i=1;i<=n1;i++)
    {
        cin>>tab[i];
        pref[i]=pref[i-1]+tab[i];
    }
    cin>>x;
    for(long long i=n1+1;i<=n;i++)
    {
        pref[i]=pref[i-1]+x;
    }
    if(x>0)
    {
        if(pref[n]>0) cout<<n;
        else cout<<-1;
        return 0;
    }
    long long maxi=-1000000000000000007;
    for(int i=0;i<n1;i++)
    {
        maxi=max(pref[i]+x*(n-i)-pref[n],maxi);
        if (maxi<x*(n-i))
        {
            cout<<n-i;
            return 0;
        }
    }
    cout<<-1;


    return 0;
}