#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int a,b,c; cin>>a>>b>>c;
    long long int res=c*2;
    res+=2*min(a,b);
    if(a!=b) res++;
    cout<<res;
    return 0;
}