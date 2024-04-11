//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=301019;
const ll mod=1000000007ll;
int w[N*4],t[N*4];
int len[N*4];
int a[N];
void build(int v,int l,int r){
    if (l==r){
        t[v]=a[l];
        w[v]=-1;
        len[v]=1;
        return;
    }
    int m=(l+r)/2;
    w[v]=-1;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=t[v+v]+t[v+v+1];
    len[v]=r-l+1;
}
void push(int v){
    if (w[v]!=-1){
        t[v+v]=w[v]*len[v+v];
        t[v+v+1]=w[v]*len[v+v+1];
        w[v+v]=w[v+v+1]=w[v];
        w[v]=-1;
    }
}
void upd(int v,int l,int r,int L,int R,int x){
    if (l>R || r<L) return;
    if (l>=L && r<=R) {
        t[v]=len[v]*x;
        w[v]=x;
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=t[v+v]+t[v+v+1];
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return t[v];
    push(v);
    int m=(l+r)/2;
    return get(v+v,l,m,L,R)+get(v+v+1,m+1,r,L,R);
}
int x[N],y[N];
void solve(){
    int n,q;cin>>n>>q;
    string A,B;cin>>A>>B;
    for (int i=1;i<=q;i++) cin>>x[i]>>y[i];
    for (int i=1;i<=n;i++){
        a[i]=(B[i-1]-'0');
    }
    build(1,1,n);
    for (int i=q;i>=1;i--){
        int cur=get(1,1,n,x[i],y[i]);
        if (cur*2==y[i]-x[i]+1){
            cout<<"NO\n";
            return;
        }
        if (cur*2<y[i]-x[i]+1){
            upd(1,1,n,x[i],y[i],0);
        } else {
            upd(1,1,n,x[i],y[i],1);
        }
    }
    for (int i=0;i<n;i++){
        if (A[i]-'0'!=get(1,1,n,i+1,i+1)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*

*/