#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
ll a[7011];
ll b[7011];
map<ll,ll>cnt;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    for (int i=1;i<=n;i++) cin>>b[i];
    vector<int>v;
    vector<int>u;
    for (int i=1;i<=n;i++){
        if (cnt[a[i]]>1) v.push_back(i);
        else u.push_back(i);
    }
    ll sum=0ll;
    for (auto i:u){
        bool ok=false;
        for (auto j:v){
            if ((a[i]&a[j])==a[i]){
                ok=true;
                break;
            }
        }
        if (ok) sum+=b[i]*1ll;
    }
    for (auto i:v) sum+=b[i]*1ll;
    cout<<sum;
    return 0;
}