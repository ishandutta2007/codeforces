#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mod=998244353;

int main()
{
    int w,h; cin>>w>>h;
    int ans=1;
    for(int i=0;i<w+h;i++)
    {
        ans*=2;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}