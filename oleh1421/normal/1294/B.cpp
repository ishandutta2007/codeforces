#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
void solve(){
    int n;cin>>n;
    vector<pair<int,int> >v(n);
    for (int i=0;i<n;i++) cin>>v[i].first>>v[i].second,swap(v[i].first,v[i].second);
    v.push_back({0,0});
    sort(v.begin(),v.end());
    for (int i=1;i<v.size();i++){
        if (v[i].second<v[i-1].second){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++){
        for (int j=v[i-1].second;j<v[i].second;j++) cout<<'R';
        for (int j=v[i-1].first;j<v[i].first;j++) cout<<'U';
    }
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}