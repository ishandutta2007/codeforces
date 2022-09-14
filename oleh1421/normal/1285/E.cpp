//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
//#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;
pair<int,int> a[400010];
int pos[400010];
pair<int,int>t[4000001];
int w[4000001];
void build(int v,int l,int r){
    t[v]={0,r-l+1};
    w[v]=0;
    if (l>=r) return;
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
}
pair<int,int>marge(pair<int,int>a,pair<int,int>b){
    if (a.first==b.first){
        a.second+=b.second;
        return a;
    }
    return min(a,b);
}
void push(int v){
    t[v+v].first+=w[v];
    t[v+v+1].first+=w[v];
    w[v+v]+=w[v];
    w[v+v+1]+=w[v];
    w[v]=0;
}
void upd(int v,int l,int r,int L,int R,int x){
//    cout<<v<<" "<<l<<" "<<r<<endl;
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v].first+=x;
        w[v]+=x;
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=marge(t[v+v],t[v+v+1]);
}
pair<int,int> get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return {1000000001,0};
    if (l>=L && r<=R) return t[v];
    push(v);
    int m=(l+r)/2;
    return marge(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n;cin>>n;
    build(1,1,n+n);
    for (int i=1;i<=n;i++) cin>>a[i].first>>a[i+n].first,a[i].second=i,a[i+n].second=i+n;
    sort(a+1,a+n+n+1);
    for (int i=1;i<=n+n;i++){
        pos[a[i].second]=i;
    }
    for (int i=1;i<=n;i++){
//        cout<<"OK\n";
//        cout<<i<<" "<<pos[i]<<" "<<pos[i+n]<<endl;
        upd(1,1,n+n,pos[i],pos[i+n]-1,1);
    }
    int maxx=0;
    for (int i=1;i<=n;i++){
        upd(1,1,n+n,pos[i],pos[i+n]-1,-1);
        auto x=get(1,1,n+n,1,n+n);
        auto y=get(1,1,n+n,pos[i],pos[i]);
        auto z=get(1,1,n+n,pos[i+n]-1,pos[i+n]-1);
        int cur=x.second;
        if (!y.first) cur-=y.second;
        if (!z.first) cur-=z.second;
        maxx=max(maxx,cur);
        upd(1,1,n+n,pos[i],pos[i+n]-1,1);
    }
    cout<<maxx<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//1 3 2 4 5 6
//1 1 1 -1 -1 -1
//1 2 3 2 1 0