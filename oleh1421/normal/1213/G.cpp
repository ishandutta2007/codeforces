#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int dsu[2000001];
ll cnt[2000001];
int dsu_find(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=dsu_find(dsu[x]);
}
ll ans[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    for (int i=1;i<=n;i++){
        cnt[i]=1ll;
        dsu[i]=i;
    }
    sort(v.begin(),v.end());
    vector<pair<int,int> >q(m);
    for (int i=1;i<=m;i++){
        cin>>q[i-1].first,q[i-1].second=i;
    }
    sort(q.begin(),q.end());
    int j=-1;
    ll res=0ll;
    for (auto x:q){
        int i=x.first;
        int pos=x.second;
        while (j+1<v.size() && v[j+1].first<=i){
             j++;
             int a=v[j].second.first;
             int b=v[j].second.second;
             res+=cnt[dsu_find(a)]*cnt[dsu_find(b)]*1ll;
             cnt[dsu_find(a)]+=cnt[dsu_find(b)];
             dsu[dsu_find(b)]=dsu_find(dsu_find(a));
        }
        ans[pos]=res;
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}


///2007521364118