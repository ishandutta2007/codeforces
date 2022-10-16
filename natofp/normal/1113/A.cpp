#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,v; cin>>n>>v;
    int ans=0;
    ans+=min(v,n-1);
    for(int i=2;i<=n-v;i++)
    {
        ans+=i;
    }
    cout<<ans;
    return 0;
}