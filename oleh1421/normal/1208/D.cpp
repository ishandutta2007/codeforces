#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <experimental/algorithm>
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int t[2000001];
int s[2000001];
void build(int v,int l,int r){
    if (l==r){
        t[v]=l;
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=t[v+v]+t[v+v+1];
}
void upd(int v,int l,int r,int pos){
     if (l>pos || r<pos) return;
     if (l==r){
        t[v]=0;
        return;
     }
     int m=(l+r)/2;
     upd(v+v,l,m,pos);
     upd(v+v+1,m+1,r,pos);
     t[v]=t[v+v]+t[v+v+1];
}
int get_pos(int v,int l,int r,int sum){
    if (l==r) return r;
    int m=(l+r)/2;
    if (t[v+v]<=sum) return get_pos(v+v+1,m+1,r,sum-t[v+v]);
    return get_pos(v+v,l,m,sum);
}
int p[1000001];
int32_t main() {
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i];
    build(1,1,n);
    for (int i=n;i>=1;i--){
        p[i]=get_pos(1,1,n,s[i]);
        upd(1,1,n,p[i]);
    }
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    return 0;
}


///2007521364118