#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool czy(long long int n)
{
    if(n<=1) return false;
    for(long long int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b;
        cin>>a>>b;
        if(a-b>1) cout<<"NO"<<endl;
        else if(czy(a+b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}