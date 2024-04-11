#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int sum=0;
        sum+=n*(n+1)/2;
        long long int k=1;
        while(k<=n)
        {
            sum-=2*k;
            k*=2;
        }
        cout<<sum<<endl;

    }
    return 0;
}