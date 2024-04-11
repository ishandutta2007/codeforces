//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
int a[300001];
map<int,int>mp;
int val[300001];
set<int>g[300001];
int ans[300001];
bool used[300001];
int t[1000001];
void upd(int v,int l,int r,int pos){
    if (l>pos || r<pos) return;
    if (l==r){
        t[v]=1;
        return;
    }
    int m=(l+r)/2;
    upd(v+v,l,m,pos);
    upd(v+v+1,m+1,r,pos);
    t[v]=t[v+v]+t[v+v+1];
}
int get(int v,int l,int r,int k){
    if (l==r) return l;
    int m=(l+r)/2;
    if (t[v+v]>=k) return get(v+v,l,m,k);
    else return get(v+v+1,m+1,r,k-t[v+v]);
}
void solve(){
    int n;cin>>n;
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++) cin>>a[i],v.push_back({a[i],-i});
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int m;cin>>m;
    vector<pair<pair<int,int>,int> >q;
    for (int i=1;i<=m;i++){
        int k,pos;cin>>k>>pos;
        q.push_back({{k,pos},i});
    }
    sort(q.begin(),q.end());
    int K=0;
    for (int i=0;i<m;i++){
        int k=q[i].first.first;
        int pos=q[i].first.second;
        int ind=q[i].second;
        while (K<k){
            int cur=-v[K].second;
          //  cout<<cur<<" ";
            upd(1,1,n,cur);
            K++;
        }
        ans[ind]=get(1,1,n,pos);
       // cout<<ans[ind]<<endl;
    }
    for (int i=1;i<=m;i++) cout<<a[ans[i]]<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}