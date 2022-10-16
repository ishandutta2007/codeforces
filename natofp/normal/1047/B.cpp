#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        ans=max(ans,x+y);
    }
    cout<<ans;
    return 0;
}