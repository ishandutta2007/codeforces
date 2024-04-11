#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n; cin>>n;
    if(((n+1)*n/2)%2==0) cout<<0;
    else cout<<1;
    return 0;
}