#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=1000010;
const ll inf=1e18;
const ll mod=998244353;
ll t[N*4];
int w[N*4];
void push(int v){
    t[v+v]+=w[v];
    t[v+v+1]+=w[v];
    w[v+v]+=w[v];
    w[v+v+1]+=w[v];
    w[v]=0;
}
void upd(int v,int l,int r,int L,int R,int x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v]+=x;
        w[v]+=x;
        return;
    }
    int m=(l+r)/2;
    push(v);
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=max(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,ll x){
    if (t[v]<x) return r+1;
    if (l==r) return l;
    int m=(l+r)/2;
    push(v);
    if (t[v+v]>=x) return get(v+v,l,m,x);
    else return get(v+v+1,m+1,r,x);
}
struct Fenwik{
    ll t[N];
    void upd(int n,int pos,ll x){
        for (;pos<=n;pos|=pos+1) t[pos]+=x;
    }
    ll get(int pos){
        ll sum=0ll;
        for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
        return sum;
    }
    ll get(int l,int r){
        if (l>r) return 0;
        if (l==0) return get(r);
        return get(r)-get(l-1);
    }
};
Fenwik T1,T2;
ll a[N],b[N];
ll diffa[N],diffb[N];

void solve(int Case){
    int n,m,q;cin>>n>>m>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    for (int i=1;i<n;i++){
        diffa[i]=a[i+1]-a[i];
    }
    for (int i=1;i<m;i++){
        diffb[i]=b[i+1]-b[i];
        upd(1,1,m-1,i,i,diffb[i]);
    }
    ll sumB=0ll;
    for (int i=1;i<=m;i++) sumB+=b[i];
    for (int it=1;it<=q;it++){
        ll type,k,d;cin>>type>>k>>d;
        if (type==1){
            for (int i=1;i<=k;i++) a[n-k+i]+=d*i;
            for (int i=1;i<=k;i++) diffa[n-1-k+i]+=d;
        } else {
            sumB+=d*k*(k+1ll)/2ll;
            T1.upd(m,m-k+1,d);
            T2.upd(m,m-k+1,d*(m-k));
//            for (int i=1;i<=k;i++) b[m-k+i]+=d*i;
            upd(1,1,m-1,max(m-k,1ll),m-1,d);
//            for (int i=1;i<=k;i++) diffb[m-1-k+i]+=d;
        }
        ll res=sumB;
        for (int i=1;i<=n;i++) res+=a[i];
        int last=1;
        for (int i=1;i<n;i++){
            int ind=get(1,1,m-1,diffa[i]);
            ll val=b[ind];
            val+=T1.get(ind)*ind-T2.get(ind);
            res+=val;
            res+=a[i]*(ind-last);
            last=ind;
        }
        res+=a[n]*(m-last);
        cout<<res<<endl;
    }

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
problem B with higher constrains


3
1 R
5 R
10 R
100 G
3 G
7 G


1
4
2 3 1 4

8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/