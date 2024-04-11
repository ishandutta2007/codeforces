#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k; cin>>n>>m>>k;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int * b=new int[n-1];
    for(int i=1;i<n;i++) b[i-1]=a[i]-a[i-1];
    sort(b,b+n-1);
    int ans=n;
    for(int i=0;i<n-k;i++)
    {
        ans+=b[i]-1;
    }
    cout<<ans;

    return 0;
}