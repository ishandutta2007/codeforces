#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,s,p;
    cin>>k>>n>>s>>p;
    int need=k*(n/s+bool(n%s));
    cout<<need/p+bool(need%p);
    return 0;
}