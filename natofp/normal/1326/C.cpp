#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

const int nax=2e5+5;
ll a[nax];
ll x[nax];
const int mod=998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll sum=0;
    for(int i=n;i>n-k;i--) sum+=i;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>n-k) x[i]=1;
    }
    int idx=-1;
    for(int i=1;i<=n;i++)
    {
        if(x[i]==1) {idx=i; break;}
    }
    vector<ll> ans;
    int akt=0;
    for(int i=idx+1;i<=n;i++)
    {
        if(x[i]==0) akt++;
        else
        {
            ans.pb(akt+1); akt=0;
        }
    }
    ll wyn=1;
    for(int i=0;i<ans.size();i++)
    {
        wyn*=ans[i];
        wyn%=mod;
    }
    cout<<sum<<" "<<wyn<<endl;
    return 0;
}