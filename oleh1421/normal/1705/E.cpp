//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=200310;
const int Lg=30;
mt19937 rnd(time(NULL));
int cnt[N];

int t[N*4];
int w[N*4];
int sz[N*4];
void build(int v,int l,int r){
    sz[v]=r-l+1;
    w[v]=0;
    t[v]=0;
    if (l==r) return;
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
}
void push(int v){
    if (w[v]){
        t[v+v]=sz[v+v]-t[v+v];
        t[v+v+1]=sz[v+v+1]-t[v+v+1];
        w[v+v]^=1;
        w[v+v+1]^=1;
        w[v]=0;
    }
}
void upd(int v,int l,int r,int L,int R){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v]=sz[v]-t[v];
        w[v]^=1;
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R);
    upd(v+v+1,m+1,r,L,R);
    t[v]=t[v+v]+t[v+v+1];
}
int FindFirst1(int v,int l,int r,int L,int R){
//    cout<<v<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<t[v]<<endl;
    if (l>R || r<L || t[v]==0) return -1;
    if (l==r) {
        return l;
    }
    push(v);
    int m=(l+r)/2;
    if (l>=L && r<=R){
        if (t[v+v]>0) return FindFirst1(v+v,l,m,L,R);
        else return FindFirst1(v+v+1,m+1,r,L,R);
    }
    int A=FindFirst1(v+v,l,m,L,R);
    if (A==-1) A=FindFirst1(v+v+1,m+1,r,L,R);
    return A;
}
int FindLast(int v,int l,int r){
    if (l==r) return l;
    push(v);
    int m=(l+r)/2;
    if (t[v+v+1]==0) return FindLast(v+v,l,m);
    return FindLast(v+v+1,m+1,r);
}
int FindFirst0(int v,int l,int r,int L,int R){

    upd(v,l,r,0,N-1);
    int ans=FindFirst1(v,l,r,L,R);
    upd(v,l,r,0,N-1);
    return ans;
}

void add(int x){
    int pos=FindFirst0(1,0,N-1,x,N-1);
    upd(1,0,N-1,x,pos);
//    for (int i=x;i<=pos;i++) cnt[i]^=1;
}
void dec(int x){
    int pos=FindFirst1(1,0,N-1,x,N-1);
    upd(1,0,N-1,x,pos);
}
int a[N];

void solve(){
    int n,q;cin>>n>>q;
    build(1,0,N-1);

    for (int i=1;i<=n;i++){
        cin>>a[i];
        add(a[i]);
    }
//    cout<<FindLast(1,0,N-1)<<endl;
    for (int it=1;it<=q;it++){
        int k,l;cin>>k>>l;
        dec(a[k]);
        a[k]=l;
        add(a[k]);
        cout<<FindLast(1,0,N-1)<<'\n';
    }




}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
//    4
//    (6/16)*(3/4*2)+
//    1
//    1 1
//    1 2 1
//    1 3 3 1
//    1 4 6 4 1
//    (1/16)
//    (4/16)*


//    1+(6/16)*(6/4)+(1/16)*0+(1/16)*0+(8/16)*2
}

//x^2+x(m-1)-m-P=0
//
//x^2+x=m+x+P
//x^2=m+P
//1+P/(m+X)

/**
14 1
9 15 17 14 8 17 3 12 20 4 19 8 4 5
5 19 10 1 12 8 1 15 20 1 13 2 18 6
1 14 28

**/