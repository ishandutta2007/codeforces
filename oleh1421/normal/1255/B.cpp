//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
void solve(){
    int n,m;cin>>n>>m;

    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        v.push_back({x,i});
    }
    if (n==2){
        cout<<-1<<endl;
        return;
    }
    sort(v.begin(),v.end());
    if (n>m){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int> >ans;
    for (int i=1;i<=n;i++) ans.push_back({i-1,i%n});
    while(ans.size()<m) ans.push_back({0,1});
    ll sum=0ll;
    for (auto i:ans) sum+=v[i.first].first+v[i.second].first;
    cout<<sum<<endl;
    for (auto i:ans) cout<<v[i.first].second<<" "<<v[i.second].second<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--) solve();
    return 0;
}