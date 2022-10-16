#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int f(int n)
{
    if(n==1) return 1;
    return (n-1)*4+f(n-1);
}


int main()
{
    int n; cin>>n;
    cout<<f(n);
    return 0;
}