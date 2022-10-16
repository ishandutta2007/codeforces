#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    if(n>m+5)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<ll> a;
    for(int i=1;i<=n;i++)
    {
        ll x; cin>>x;
        a.push_back(x);
    }
    ll res=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ll akt=abs(a[i]-a[j]);
            akt%=m;
            res*=akt;
            res%=m;
        }
    }
    cout<<res;
    return 0;
}