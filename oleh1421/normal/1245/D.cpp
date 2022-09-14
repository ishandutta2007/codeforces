#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
ll x[2020];
ll y[2020];
ll k[2020];
ll c[2020];
int dsu[2020];
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) cin>>k[i];
    for (int i=0;i<=n;i++) dsu[i]=i;
    vector<pair<ll,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        v.push_back({c[i],{0,i}});
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            v.push_back({(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]),{i,j}});
        }
    }
    sort(v.begin(),v.end());
    ll res=0ll;
    vector<int>ans;
    vector<pair<int,int> >u;
    for (auto cur:v){
        int a=cur.second.first;
        int b=cur.second.second;
        if (get(a)!=get(b)){
            dsu[get(a)]=get(b);
            if (a && b) u.push_back({a,b});
            else if (a) ans.push_back(a);
            else ans.push_back(b);
            res+=cur.first*1ll;
        }
    }
    cout<<res<<endl;
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for (auto i:ans) cout<<i<<" ";
    cout<<endl;
    cout<<u.size()<<endl;
    for (auto i:u) cout<<i.first<<" "<<i.second<<endl;
    return 0;
}