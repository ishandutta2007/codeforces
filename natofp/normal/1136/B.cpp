#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    int res=0;
    res+=min(k-1,n-k);
    res+=3*(n-1);
    res+=3;
    cout<<res;
    return 0;
}