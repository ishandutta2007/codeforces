#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll n;
    cin>>n;
    vector<ll> cc;
    ll begin[n+1];
    ll end[n];
    
    for(ll i=0;i<n;i++)
    {
        cin>>begin[i]>>end[i];
        cc.push_back(begin[i]);
        cc.push_back(end[i]+1);
    }
    
    sort(cc.begin(), cc.end());
	cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
	
	ll counter[2*n] = {0};
	for(ll i=0;i<n;i++)
    {
        ll idx = lower_bound(cc.begin(), cc.end(), begin[i]) - cc.begin();
        counter[idx]++;
        idx = lower_bound(cc.begin(), cc.end(), end[i]+1) - cc.begin();
        counter[idx]--;
    }
    
    for(ll i=1;i<2*n;i++)
    {
        counter[i] += counter[i-1];
    }
    
    for(ll i=0;i<=n;i++)
    {
        begin[i]=0;
    }
    
    for(ll i=0;i<2*n;i++)
    {
        begin[counter[i]] += cc[i+1] - cc[i];
    }
    
    for(ll i=1;i<=n;i++)
    {
        cout<<begin[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}