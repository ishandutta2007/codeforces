#include<bits/stdc++.h>
typedef long long ll;
//#define endl '\n'

using namespace std;
const int N=1000010;
const int A=10000001;
int Q=0;
int ask(int l,int r){
    Q++;
    if (Q>60000) exit(1);
    cout<<"? "<<l<<" "<<r<<endl;
    int ans;cin>>ans;
    return ans;
}
int t[N*4];
void build(int v,int l,int r){
    t[v]=-1;
    if (l==r) return;
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
}
int get(int v,int l,int r,int k){
//    if (l==r){
//        if (t[v]==-1) t[v]=(r-l+1)-ask(l,r);
//        if (t[v]<k) return -1;
//        return l;
//    }
    if (t[v]==-1) t[v]=(r-l+1)-ask(l,r);
    if (t[v]<k) return -1;
    if (l==r) return l;
    int m=(l+r)/2;
    int ans=get(v+v,l,m,k);
    t[v+v+1]=t[v]-t[v+v];
    if (ans==-1) ans=get(v+v+1,m+1,r,k-t[v+v]);
    return ans;
}
void upd(int v,int l,int r,int pos,int x){
    t[v]+=x;
    if (l==r) return;
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos,x);
    else upd(v+v+1,m+1,r,pos,x);
}
void solve(){
    int n,t;cin>>n>>t;
    build(1,1,n);
    while (t--){
        int k;cin>>k;

        int ans=get(1,1,n,k);
        if (ans==-1) ans=n+1;
        cout<<"! "<<ans<<endl;
        if (ans<=n) upd(1,1,n,ans,-1);
    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}