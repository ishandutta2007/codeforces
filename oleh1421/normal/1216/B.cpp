#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int long long
using namespace std;
int a[200001];
void solve(){
    int n;cin>>n;
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll res=0ll;
    for (int i=0;i<n;i++){
        res+=(v[i].first*i*1ll+1);
    }
    cout<<res<<endl;
    for (auto i:v) cout<<i.second<<" ";

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;tt=1;
    while (tt--){
        solve();
    }
    return 0;
}