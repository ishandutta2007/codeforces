#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

bool ok (ll n)
{
    while(n)
    {
        if(n%3==2) return false;
        n/=3;
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        ll n; cin>>n;
        while(ok(n)==false) n++;
        cout<<n<<endl;
    }
    return 0;
}