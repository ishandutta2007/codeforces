#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    long long int res;
    if(n%2==1)
    {
        cout<<0;
        return 0;
    }
    n/=2;
    res=1;
    for(int i=0;i<n;i++) res*=2;
    cout<<res;

    return 0;
}