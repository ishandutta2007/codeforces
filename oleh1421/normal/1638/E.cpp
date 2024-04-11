//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=1000010;
int eq[N*4];
ll t[N*4];
int mn[N*4];
int mx[N*4];
ll a[N];
int c[N];
ll add[N];
void build(int v,int l,int r){
    t[v]=eq[v]=0;
    if (l==r){
        t[v]=a[l];
        mn[v]=mx[v]=c[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    mn[v]=min(mn[v+v],mn[v+v+1]);
    mx[v]=max(mx[v+v],mx[v+v+1]);
}
void push(int v){
    t[v+v]+=t[v];
    t[v+v+1]+=t[v];
    t[v]=0;
    if (eq[v]){
        mn[v+v]=mn[v+v+1]=mx[v+v]=mx[v+v+1]=eq[v+v]=eq[v+v+1]=eq[v];
        eq[v]=0;
    }
}
void upd(int v,int l,int r,int L,int R,int c){
    if (l>R || r<L) return;
    if (l>=L && r<=R && mn[v]==mx[v]){
        t[v]+=add[mn[v]]-add[c];
        eq[v]=mn[v]=mx[v]=c;
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,c);
    upd(v+v+1,m+1,r,L,R,c);
    mn[v]=min(mn[v+v],mn[v+v+1]);
    mx[v]=max(mx[v+v],mx[v+v+1]);
}
ll get(int v,int l,int r,int pos){
    if (l==r) return t[v]+add[mn[v]];
    push(v);
    int m=(l+r)/2;
    if (pos<=m) return get(v+v,l,m,pos);
    else return get(v+v+1,m+1,r,pos);
}
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++){
        a[i]=0;
        c[i]=1;
    }
    build(1,1,n);
    for (int it=1;it<=q;it++){
        string type;cin>>type;
        if (type=="Add"){
            int c,x;cin>>c>>x;
            add[c]+=x;
        } else if (type=="Color"){
            int l,r,c;cin>>l>>r>>c;
            upd(1,1,n,l,r,c);
        } else {
            int ind;cin>>ind;
            cout<<get(1,1,n,ind)<<endl;
        }
    }

}

int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;

    while (tt--){
        solve();
    }
    return 0;
}

/**
1
4 2
1 2
1 3
1 4
**/