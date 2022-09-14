#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
int a[N];
int b[N];
int dsu[N];
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
//vector<int>A[N];
void solve(){
    int m,n;cin>>m>>n;
    for (int i=1;i<=m;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n+m;i++) dsu[i]=i;
    vector<pair<ll,pair<int,int> > >v;
    for (int i=1;i<=m;i++){
        int k;cin>>k;
        for (int j=1;j<=k;j++){
            int x;cin>>x;
            v.push_back({a[i]+b[x],{i,m+x}});
//            A[i].push_back(x);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll res=0ll;
    for (auto cur:v){
        int x=cur.second.first;
        int y=cur.second.second;
        x=get(x);
        y=get(y);
        if (x==y) {
//            cout<<cur.second.first<<" "<<cur.second.second<<endl;
            res+=cur.first;
        }
        else dsu[x]=y;
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