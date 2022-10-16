#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m; cin>>n>>m;
    if(m*2<=n)
    {
        if(m==0) cout<<1;
        else cout<<m;
    }
    else
    {
        cout<<n-m;
    }
    return 0;
}