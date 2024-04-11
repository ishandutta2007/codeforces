#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
    int n,k1,k2; cin>>n>>k1>>k2;
    bool ok = false;
    for(int i=1;i<=k1;i++)
    {
        int x; cin>>x; if(x==n) ok = true;
    }
    for(int i=1;i<=k2;i++)
    {
        int x; cin>>x;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}