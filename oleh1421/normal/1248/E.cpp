#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
const ll mod=1000000007ll;
ll a[N];
ll t[N*4];
ll w[N*4];
void build(int v,int l,int r){
    w[v]=0;
    if (l==r){
        t[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=min(t[v+v],t[v+v+1]);
}
void push(int v){
    t[v+v]=max(t[v+v],w[v]);
    t[v+v+1]=max(t[v+v+1],w[v]);
    w[v+v]=max(w[v+v],w[v]);
    w[v+v+1]=max(w[v+v+1],w[v]);
    w[v]=0;
}
pair<ll,int>get(int v,int l,int r){
    if (l==r) return {t[v],l};
    push(v);
    int m=(l+r)/2;
    if (t[v+v]<=t[v+v+1]) return get(v+v,l,m);
    else return get(v+v+1,m+1,r);
}
void upd(int v,int l,int r,int L,int R,ll x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v]=max(t[v],x);
        w[v]=max(w[v],x);
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=min(t[v+v],t[v+v+1]);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,p;cin>>n>>p;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    ll last=0ll;
    for (int i=1;i<=n;i++){

        auto cur=get(1,1,n);
        last=max(last,cur.first)+p;
//        cout<<cur.second<<" "<<cur.first<<" "<<t[1]<<endl;
        a[cur.second]=last;
        upd(1,1,n,cur.second,n,last);
        upd(1,1,n,cur.second,cur.second,100000000000000001ll);
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
///try to solve I
/*
3 1
1 1
1 2
2 1
1 3
3 1
*/