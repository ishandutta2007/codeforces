#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=600010;
const ll mod=1000000007ll;
int a[N];
int pos[N];
int x[N];
int y[N];
ll p[N];
int last[N];
struct node{
    ll dp;
    ll sum;
    ll pref;
    ll suf;
    ll sz;
};
node marge(node l,node r){
    if (!l.sz) return r;
    if (!r.sz) return l;
    node res;
    res.sum=(l.sum+r.sum)%mod;
    res.sz=l.sz+r.sz;
    res.pref=(l.pref+p[l.sz]*r.pref)%mod;
    res.suf=(r.suf+p[r.sz]*l.suf)%mod;
    res.dp=(l.dp*p[r.sz]+r.dp*p[l.sz]+l.pref*r.suf)%mod;
    return res;
}
node t[N*4];
void build(int v,int l,int r){
    if (l>r) return;
    if (l==r){
        int x=a[l];
        if (!x) t[v].sz=t[v].sum=t[v].pref=t[v].suf=t[v].dp=0ll;
        else {
            t[v].sz=1ll;
            t[v].sum=t[v].pref=t[v].suf=x;
            t[v].dp=0ll;
        }
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=marge(t[v+v],t[v+v+1]);
}
void upd(int v,int l,int r,int pos,int x){
    if (l>pos || r<pos) return;
    if (l==r){
        if (!x) t[v].sz=t[v].sum=t[v].pref=t[v].suf=t[v].dp=0ll;
        else {
            t[v].sz=1ll;
            t[v].sum=t[v].pref=t[v].suf=x;
            t[v].dp=0ll;
        }
        return;
    }
    int m=(l+r)/2;
    upd(v+v,l,m,pos,x);
    upd(v+v+1,m+1,r,pos,x);
    t[v]=marge(t[v+v],t[v+v+1]);
//    cout<<v<<" "<<t[v].sz<<endl;
}
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2ll) return (binpow(a,b-1ll)*a)%mod;
    else return binpow((a*a)%mod,b/2ll);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    p[0]=1ll;
    for (int i=1;i<=n;i++){
        p[i]=(p[i-1]*2ll)%mod;
    }
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        v.push_back({x,i});
        last[i]=i;
    }
    int q;cin>>q;
    for (int i=1;i<=q;i++){
        cin>>y[i]>>x[i];
        int j=y[i];
        y[i]=last[y[i]];
        last[j]=i+n;
        v.push_back({x[i],i+n});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n+q;i++){
        pos[v[i].second]=i+1;
        if (v[i].second<=n) a[i+1]=v[i].first;
        else a[i+1]=0;
    }
    build(1,1,n+q);
    ll mult=binpow(binpow(2ll,n),mod-2ll);
    cout<<(t[1].dp*mult)%mod<<endl;
    for (int i=1;i<=q;i++){
        upd(1,1,n+q,pos[y[i]],0);
        upd(1,1,n+q,pos[i+n],x[i]);
        cout<<(t[1].dp*mult)%mod<<endl;
    }
    return 0;
}