//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;

using namespace std;
int a[200001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    vector<int>u;
    for (int i=2;i<=sum;i++){
        if (sum%i==0){
            u.push_back(i);
        }
    }
    ll minx=-1ll;
    for (auto d:u){
        vector<int>v;
        ll res=0ll;
        for (int i=1;i<=n;i++){
            if (a[i]) v.push_back(i);
            if (v.size()==d){
                ll cur=0;
                ll x=v[d/2]*1ll;
                for (auto i:v) cur+=abs(x-i*1ll);
                res+=cur;
                v.clear();
            }
        }
        if (minx==-1 || res<minx) minx=res;
    }
    cout<<minx;
    return 0;
}