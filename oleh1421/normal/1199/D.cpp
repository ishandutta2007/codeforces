#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int a[200001];
int w[800001];
int t[800001];
void build(int v,int l,int r){
     if (l==r){
        t[v]=a[l];
        return;
     }
     int m=(l+r)/2;
     build(v+v,l,m);
     build(v+v+1,m+1,r);
     t[v]=max(t[2*v],t[2*v+1]);
}
void push(int v){
     t[2*v]=max(t[2*v],w[v]);
     t[2*v+1]=max(t[2*v+1],w[v]);
     w[2*v]=max(w[2*v],w[v]);
     w[2*v+1]=max(w[2*v+1],w[v]);
     w[v]=0;
}
void upd(int v,int l,int r,int p,int x){
     if (l>p || r<p) return;
     if (l==r){
        t[v]=x;
        return;
     }
     int m=(l+r)/2;
     push(v);
     upd(2*v,l,m,p,x);
     upd(2*v+1,m+1,r,p,x);
     t[v]=max(t[2*v],t[2*v+1]);
}
int get(int v,int l,int r,int p){
     if (l>p || r<p) return 0;
     if (l==r) return t[v];
     int m=(l+r)/2;
     push(v);
     return max(get(2*v,l,m,p),get(2*v+1,m+1,r,p));
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    int q;cin>>q;
    for (int i=1;i<=q;i++){
        int type;cin>>type;
        if (type==1){
            int p,x;cin>>p>>x;
            upd(1,1,n,p,x);
        } else {
            int x;cin>>x;
            w[1]=max(w[1],x);
            t[1]=max(t[1],x);
        }
    }
    for (int i=1;i<=n;i++) cout<<get(1,1,n,i)<<" ";
    return 0;
}