#include <bits/stdc++.h>
using namespace std;
const int N=100010;
typedef long long ll;
ll bt[N];
vector<long long> v,V;
int n;
void upd(int i,ll val)
{
    while(i<=n)
    {
        bt[i]=max(bt[i],val);
        i+=i&-i;
    }
}
ll qry(int i)
{
    ll ans=0;
    while(i>0)
    {
        ans=max(ans,bt[i]);
        i-=i&-i;
    }
    return ans;
}

int main()
{
    
    cin>>n;
    v.resize(n);
    V.resize(n);
    ll ans=0;
    for(int i=0;i<n;++i)
    {
        ll r,h;
        cin>>r>>h;
        v[i]=r*r*h;
        V[i]=v[i];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<n;++i)
    {
        int pos = lower_bound(v.begin(),v.end(),V[i])-v.begin()+1;
        ll prev=qry(pos-1);
        upd(pos,prev+V[i]);
        ans=max(ans,prev+V[i]);
    }
    cout<<fixed<<setprecision(10)<<ans*4*atan((long double)1.0);
    
    return 0;
}