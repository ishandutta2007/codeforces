#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,s;
    cin>>n>>s;
    cout<<s/n+bool(s%n);
    return 0;
}