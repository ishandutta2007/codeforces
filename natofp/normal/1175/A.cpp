#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int t; cin>>t;
    while(t--)
    {
        long long int n,k; cin>>n>>k;
        long long int res=0;
        while(n>0)
        {
            if(n%k==0)
        {
            n/=k; res++;
        }
        else
        {
            res+=n%k;
            n-=n%k;
        }
        }
        cout<<res<<" ";
    }
    return 0;
}