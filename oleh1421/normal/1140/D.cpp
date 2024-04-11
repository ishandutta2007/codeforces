#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;cin>>n;
    ll sum=0ll;
    for (int i=2;i<n;i++){
        sum+=i*(i+1ll)*1ll;
    }
    cout<<sum;
    //int n,k;cin>>n>>k;
    /*vector<pair<ll,ll> >v(n+10);
    for (int i=0;i<n;i++) cin>>v[i].second>>v[i].first;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll sum=0ll;
    set<ll>s;
    ll ans=0ll;
    for (int i=0;i<n;i++){
        int cur=v[i].first;
        while (i+1<n && cur==v[i+1].first) {
              s.insert(v[i].second*1ll);
              sum+=v[i].second*1ll;
                i++;
        }
        s.insert(v[i].second*1ll);
        sum+=v[i].second*1ll;
        while (s.size()>k){
            ll minx=1ll*(*s.begin());
            sum-=minx;
            s.erase(s.begin());
        }
        ans=max(ans*1ll,sum*1ll*v[i].first*1ll);
    }
    cout<<ans*1ll;*/
    return 0;
}