#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    int t=n%k;
    cout<<n+(k-t);
    return 0;
}