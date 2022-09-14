#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=2010;
int a[N],b[N],c[N],d[N];

void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for (int i=1;i<=m;i++) cin>>c[i]>>d[i];
    vector<pair<int,int> >v;
    v.push_back({-1,1000000001});
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i]<=c[j] && b[i]<=d[j]){
                v.push_back({c[j]-a[i],d[j]-b[i]+1});
            }
        }
    }
    int res=1000000001;
    v.push_back({res,0});
    sort(v.begin(),v.end());
    for (int i=(int)v.size()-2;i>=0;i--){
        v[i].second=max(v[i].second,v[i+1].second);
    }
    for (int i=1;i<v.size();i++){
//        cout<<v[i].first<<" "<<v[i].second<<endl;
        res=min(res,v[i-1].first+1+v[i].second);
    }
    cout<<res<<endl;


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}