//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <algorithm>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000105;
ll a[N];
struct SegTree{
    ll w[N*4],t[N*4];
    void build(int v,int l,int r){
        t[v]=w[v]=0;
        if (l==r) return;
        int m=(l+r)/2;
        build(v+v,l,m);
        build(v+v+1,m+1,r);
    }
    void push(int v){
        t[v+v]+=w[v];
        t[v+v+1]+=w[v];
        w[v+v]+=w[v];
        w[v+v+1]+=w[v];
        w[v]=0;
    }
    void upd(int v,int l,int r,int L,int R,ll x){

        if (l>R || r<L) return;
        if (l>=L && r<=R) {
            t[v]+=x;
            w[v]+=x;
            return;
        }
        push(v);
        int m=(l+r)/2;
        upd(v+v,l,m,L,R,x);
        upd(v+v+1,m+1,r,L,R,x);
        t[v]=min(t[v+v],t[v+v+1]);
    }
    ll Find(int v,int l,int r){
        if (t[v]>=0) return N;
        if (l==r) return l;
        int m=(l+r)/2;
        push(v);
        if (t[v+v]<0) return Find(v+v,l,m);
        else return Find(v+v+1,m+1,r);
    }
};
SegTree T[2];
map<ll,vector<int> >mp[2];
ll sum[N];
void solve(){
    mp[0].clear();
    mp[1].clear();
    ///n-th element 2*k
    int n;cin>>n;
    sum[0]=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=a[i]-sum[i-1];
        mp[i%2][sum[i]].push_back(i);
    }
    T[0].build(1,1,(n+1)/2);
    T[1].build(1,1,(n+1)/2);
    ll res=0ll;
//    T[1].upd(1,1,(n+1)/2,2,(n+1)/2,-5);
//    cout<<T[1].Find(1,1,(n+1)/2)<<endl;
    for (int l=n;l>=1;l--){
        T[l%2].upd(1,1,(n+1)/2,(l+1)/2,(n+1)/2,a[l]);
        T[(l+1)%2].upd(1,1,(n+1)/2,(l+2)/2,(n+1)/2,-a[l]);
        int ind=min(T[0].Find(1,1,(n+1)/2)*2,T[1].Find(1,1,(n+1)/2)*2-1);
//        cout<<l<<" "<<ind<<" "<<T[0].Find(1,1,(n+1)/2)*2<<" "<<T[1].Find(1,1,(n+1)/2)*2-1<<endl;
        auto &v1=mp[l%2][-sum[l-1]];
        res+=lower_bound(v1.begin(),v1.end(),ind)-lower_bound(v1.begin(),v1.end(),l);
        auto &v2=mp[(l+1)%2][sum[l-1]];
        res+=lower_bound(v2.begin(),v2.end(),ind)-lower_bound(v2.begin(),v2.end(),l);
//
//        cout<<sum[l-1]<<" "<<l<<" "<<lower_bound(v2.begin(),v2.end(),ind)-lower_bound(v2.begin(),v2.end(),l)<<endl;
//                for (int x:v2) cout<<x<<" ";
//        cout<<endl;
    }
    cout<<res<<endl;


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
/**
100000000 3
0 0 0 1 1
**/