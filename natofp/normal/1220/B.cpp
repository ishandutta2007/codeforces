#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int nax=1005;
ll a[nax][nax];

vector<ll> daj(ll k)
{
    vector<ll> res;
    for(int i=1;i*i<=k;i++)
    {
        if(i*i==k) res.push_back(i);
        else
        {
            res.push_back(i);
            res.push_back(k/i);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    int ile=a[2][1];
    for(int i=2;i<=n;i++)
    {
        ile=__gcd(ile,(int)a[i][1]);
    }
    vector<ll> d=daj(ile);
    for(int i=0;i<d.size();i++)
    {
        ll akt=d[i];
        ll a2=a[2][1]/akt;
        ll a3=a[3][1]/akt;
        if(a2*a3!=a[2][3]) continue;
        cout<<akt<<" ";
        for(int i=2;i<=n;i++)
        {
            cout<<a[i][1]/akt<<" ";
        }
        return 0;
    }
    return 0;
}