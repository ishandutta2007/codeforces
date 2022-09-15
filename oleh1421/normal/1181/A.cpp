#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

int main()
{
    ll x,y,z;cin>>x>>y>>z;
    cout<<1ll*(x+y)/z*1ll<<" ";
    if (1ll*(x+y)/z*1ll>(x/z)*1ll+(y/z)*1ll) cout<<min({((z-x%z)%z),((z-y%z)%z),x,y});
    else cout<<0;
    return 0;
}