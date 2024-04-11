#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        long long int ans=0;
        long long int s,a,b,c;
        cin>>s>>a>>b>>c;
        long long int koszt=a*c;
        long long int x=s/koszt;
        s-=x*koszt;
        ans+=x*a+x*b;
        ans+=s/c;
        cout<<ans<<endl;
    }
    return 0;
}