#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll a,b,n; cin>>a>>b>>n;
        if(n%3==0) cout<<a<<endl;
        else if(n%3==1) cout<<b<<endl;
        else cout<<(a^b)<<endl;

    }
    return 0;
}