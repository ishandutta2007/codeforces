//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=400004;
int a[N];
ll sum[N*4];
int mn[N*4];
int sz[N*4];
int w[N*4];
void build(int v,int l,int r){
    if (l>r) return;
    if (l==r){
        sum[v]=mn[v]=a[l];
        if (!a[l]) sum[v]=1000000001;
        sz[v]=1;
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    sum[v]=sum[v+v]+sum[v+v+1];
    sz[v]=sz[v+v]+sz[v+v+1];
    mn[v]=mn[v+v+1];
}
void push(int v){
    if (w[v]){
        sum[v+v]=(sz[v+v]*1ll)*(w[v]*1ll);
        sum[v+v+1]=(sz[v+v+1]*1ll)*(w[v]*1ll);
        mn[v+v]=mn[v+v+1]=w[v+v]=w[v+v+1]=w[v];
        w[v]=0;
    }
}
void upd(int v,int l,int r,int L,int R,int x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        sum[v]=(sz[v]*1ll)*(x*1ll);
        mn[v]=x;
        w[v]=x;
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    sum[v]=sum[v+v]+sum[v+v+1];
    sz[v]=sz[v+v]+sz[v+v+1];
    mn[v]=mn[v+v+1];
}
int get_sum(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return sum[v];
    push(v);
    int m=(l+r)/2;
    return get_sum(v+v,l,m,L,R)+get_sum(v+v+1,m+1,r,L,R);
}
int Find(int v,int l,int r,int L,int R,int x){
    if (l==r) return l;
    push(v);
    int m=(l+r)/2;
    if (m<L || mn[v+v]>x) return Find(v+v+1,m+1,r,L,R,x);
    else return Find(v+v,l,m,L,R,x);
}
int go(int v,int l,int r,int L,int R,int x){
//    cout<<"OOOK\n";
    if (l>R || r<L) return 0;
    if (l==r){
        if (sum[v]>x) return l;
        return -sum[v];
    }
    push(v);
    int m=(l+r)/2;
    if (l>=L && r<=R){
//        if (l==4 && r==6) cout<<"OOOK "<<x<<" "<<sum[v]<<endl;
//        cout<<l<<" "<<r<<" uuuuuups\n";
        if (sum[v]<=x) return -sum[v];
        else if (sum[v+v]<=x) return go(v+v+1,m+1,r,L,R,x-sum[v+v]);
        else return go(v+v,l,m,L,R,x);
    }
    int res=go(v+v,l,m,L,R,x);
//    cout<<l<<" "<<r<<" "<<m<<" "<<x<<" "<<res<<endl;
    if (res>0) return res;
//    cout<<"OKaaa\n";
    x+=res;
    int res1=go(v+v+1,m+1,r,L,R,x);
    if (res1<=0) res1+=res;
    return res1;
}
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=0;
    build(1,1,n+1);
//    cout<<Find(1,1,n+1,1,n+1,4)<<endl;
//    cout<<"OK"<<endl;
    for (int it=1;it<=q;it++){
        int type,x,y;cin>>type>>x>>y;
        if (type==1){
            int pos=Find(1,1,n+1,1,n+1,y);
            if (pos<=x){
                upd(1,1,n+1,pos,x,y);
            }
        } else {
            int res=0;
            while (x<=n){
                x=Find(1,1,n+1,x,n+1,y);
//                cout<<x<<" "<<y<<endl;
                if (x>n) break;
                int nxt=go(1,1,n+1,x,n+1,y);
                res+=nxt-x;
                y-=get_sum(1,1,n+1,x,nxt-1);
                x=nxt;
//                exit(1);
            }
            cout<<res<<endl;
        }
    }

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/*
10 1
10 10 10 6 6 5 5 5 3 1
2 2 36

*/