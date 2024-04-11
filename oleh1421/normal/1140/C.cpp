#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,k;cin>>n>>k;
    vector<pair<ll,ll> >v(n,{0ll,0ll});
    for (int i=0;i<n;i++) cin>>v[i].second>>v[i].first;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll sum=0ll;
    multiset<ll>s;
    ll ans=0ll;
    for (int i=0;i<n;i++){
        if (s.size()+1>k){
            ll minix=(*s.begin());
            ll minx=minix*1ll;
            sum-=minx*1ll;
            s.erase(s.begin());
        }
        s.insert(v[i].second*1ll);
        sum+=v[i].second*1ll;
        ans=max(ans*1ll,sum*1ll*v[i].first*1ll);
    }
    cout<<ans*1ll;
    return 0;
}