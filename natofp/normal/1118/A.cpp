#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        long long int n,a,b; cin>>n>>a>>b;
        if(a*2<=b) {cout<<n*a<<endl; continue;}
        cout<<((n/2)*b+(n%2)*a)<<endl;
    }
    return 0;
}