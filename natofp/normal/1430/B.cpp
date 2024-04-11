#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

void solve()
{
    int n,k; cin>>n>>k;
    vector<ll> a;
    for(int i=1;i<=n;i++)
    {
        ll x; cin>>x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    ll ans = a.back();
    for(int i=n-2;i>=0;i--)
    {
        k--;
        ans += a[i];
        if(k == 0) break;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}