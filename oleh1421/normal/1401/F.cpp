#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=(1<<20);
const int inf=1000000001;
#define endl '\n'
ll a[N];
int pos[N];
int n,q;
int Xr=0;
ll t[N*4];
void build(int v,int l,int r){
    if (l==r){
        t[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=t[v+v]+t[v+v+1];
}
void upd(int v,int l,int r,int pos){
    if (l==r){
        t[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos);
    else upd(v+v+1,m+1,r,pos);
    t[v]=t[v+v]+t[v+v+1];
}
ll get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0ll;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return get(v+v,l,m,L,R)+get(v+v+1,m+1,r,L,R);
}
ll solve(int r){
    if (r==-1) return 0;
    ll res=0ll;
    for (int i=0;i<n;i++){
        if (r&(1<<i)){
            int pref=((r-r%(1<<(i+1)))^(Xr-Xr%(1<<(i+1))));
            int bt=(Xr>>i)%2;
            res+=get(1,0,(1<<n)-1,pref+(bt<<i),pref+(1<<i)-1+(bt<<i));
        }
    }
    res+=a[r^Xr];
    return res;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for (int i=0;i<(1<<n);i++) cin>>a[i],pos[i]=i;
    build(1,0,(1<<n)-1);
    for (int it=1;it<=q;it++){
        int type;cin>>type;
        if (type==1){
            int x,k;cin>>x>>k;
            x--;
            a[x^Xr]=k;
            upd(1,0,(1<<n)-1,x^Xr);
        } else if (type==2){
            int k;cin>>k;
            Xr^=(1<<k)-1;
        } else if (type==3){
            int k;cin>>k;
            Xr^=(1<<k);
        } else {
            ll sum=0ll;
            int l,r;cin>>l>>r;
            l--;
            r--;
//            cout<<"OK\n";
//            cout<<l<<" "<<r<<" "<<Xr<<endl;
//            for (int i=0;i<(1<<n);i++) cout<<a[i]<<" ";
//            cout<<endl;
            cout<<solve(r)-solve(l-1)<<endl;
//            cout<<solve(r)<<endl;
        }
    }
    return 0;
}
//0 1 2 3
//2 3 0 1
/////type 1:
//    pos[i]^=(1<<k)-1
//
/////type 2:
//    pos[i]^=(1<<k)