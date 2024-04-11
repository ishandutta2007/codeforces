#pragma GCC optimize ("Ofast")
/// #pragma GCC target("avx2")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
using namespace std;
int a[1000001];
int t[1000001];
int w[1000001];
int t1[1000001];
int w1[1000001];
void build(int v,int l,int r){
     if (l==r){
        t[v]=a[l];
        t1[v]=a[l];
        return;
     }
     int m=(l+r)/2;
     build(2*v,l,m);
     build(2*v+1,m+1,r);
     t[v]=max(t[2*v],t[2*v+1]);
     t1[v]=min(t1[2*v],t1[2*v+1]);
}
void push(int v){
     t[2*v]+=w[v];
     t[2*v+1]+=w[v];
     w[2*v]+=w[v];
     w[2*v+1]+=w[v];
     w[v]=0;
     t1[2*v]+=w1[v];
     t1[2*v+1]+=w1[v];
     w1[2*v]+=w1[v];
     w1[2*v+1]+=w1[v];
     w1[v]=0;
}
void upd(int v,int l,int r,int L,int R,int x){
     if (l>R || r<L) return;
     if (l>=L && r<=R){
         w[v]+=x;
         t[v]+=x;
         t1[v]+=x;
         w1[v]+=x;
         return;
     }
     int m=(l+r)/2;
     push(v);
     upd(2*v,l,m,L,R,x);
     upd(2*v+1,m+1,r,L,R,x);
     t[v]=max(t[2*v],t[2*v+1]);
     t1[v]=min(t1[2*v],t1[2*v+1]);
}
int getMax(int v,int l,int r,int L,int R){
    if (l>R || r<L) return -2000000001;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    push(v);
    return max(getMax(2*v,l,m,L,R),getMax(2*v+1,m+1,r,L,R));
}
int getMin(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 2000000001;
    if (l>=L && r<=R) return t1[v];
    int m=(l+r)/2;
    push(v);
    return min(getMin(2*v,l,m,L,R),getMin(2*v+1,m+1,r,L,R));
}
int l[1000001];
int r[1000001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
    int index=0;
    int maxx=-1;
    int x=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (l[j]<=i && r[j]>=i) continue;
            upd(1,1,n,l[j],r[j],-1);
        }
        int cur=getMax(1,1,n,1,n)-getMin(1,1,n,1,n);
        if (cur>maxx){
            maxx=cur;
            index=i;
        }
        for (int j=1;j<=m;j++){
            if (l[j]<=i && r[j]>=i) continue;
            upd(1,1,n,l[j],r[j],1);
        }
    }
    cout<<maxx<<endl;
    vector<int>v;
    for (int j=1;j<=m;j++){
        if (l[j]<=index && r[j]>=index) continue;
        v.push_back(j);
    }
    cout<<v.size()<<endl;
    for (auto i:v) cout<<i<<" ";
    return 0;
}
//0 -4 1 1 2