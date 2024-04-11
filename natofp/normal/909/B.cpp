#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n; cin>>n;
    int res=0;
    if(n%2==0)
    {
        res=(n/2)*(n/2+1);
    }
    else res=(((n+1)/2)*((n+1)/2));
    cout<<res;
    return 0;
}