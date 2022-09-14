#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500100;
ll w[N];
void solve(){
    int n;cin>>n;
    ll W;cin>>W;
    vector<pair<ll,int> >v;
    for (int i=1;i<=n;i++){
        cin>>w[i];
        if (w[i]<=W){
            v.push_back({w[i],i});
        }
    }
    sort(v.begin(),v.end());
    if (v.empty()){
        cout<<-1<<endl;
        return;
    }
    if (v.back().first>=(W+1ll)/2ll){
        cout<<1<<endl;
        cout<<v.back().second<<endl;
        return;
    }
    ll sum=0ll;
    vector<int>ans;
    for (auto cur:v){
        ans.push_back(cur.second);
        sum+=cur.first;
        if (sum>=(W+1ll)/2ll) break;
    }
    if (sum<(W+1ll)/2ll){
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}