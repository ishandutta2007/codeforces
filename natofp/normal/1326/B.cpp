#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

const int nax=2e5+5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<ll> b;
    for(int i=1;i<=n;i++)
    {
        ll x; cin>>x;
        b.pb(x);
    }
    vector<ll> a;
    ll naj=0;
    for(int i=0;i<n;i++)
    {
        a.pb(b[i]+naj);
        naj=max(naj,a[i]);
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}