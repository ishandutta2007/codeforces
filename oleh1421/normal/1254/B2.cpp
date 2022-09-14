//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;

using namespace std;
int a[1000155];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    ll sum=0;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i]*1ll;
    vector<ll>u;
    for (ll i=2;i*i<=sum;i++){
        if (sum%i==0){
            u.push_back(i);
            while (sum%i==0) sum/=i;
        }
    }
    if (sum>1) u.push_back(sum);
    ll minx=-1ll;
    int cnt=0;
    for (ll d:u){
        vector<pair<ll,pair<ll,ll> > >v;
        ll v_sz=0ll;
        ll res=0ll;
        vector<int>last;
        for (int i=1;i<=n;i++){
            last.push_back(a[i]);
            a[i]%=d;
            ll add=min(a[i]*1ll,d-v_sz);
            v_sz+=add;
            v.push_back({v_sz,{add,i}});
            a[i]-=add;
            cnt++;
            if (v_sz==d){
                pair<ll,pair<ll,ll> >fnd={d/2ll+1,{-1,-1}};
                int it=lower_bound(v.begin(),v.end(),fnd)-v.begin();
                ll cur=v[it].second.second;
                for (auto j:v) res+=abs(cur-j.second.second)*j.second.first;
                v.clear();
                v_sz=a[i];
                v.push_back({v_sz,{a[i],i}});
            }
        }
        for (int i=1;i<=n;i++) a[i]=last[i-1];
        if (minx==-1 || res<minx) minx=res;
    }
    cout<<minx;
    return 0;
}