#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=2000010;
int a[N];
int t[N*4];
void build(int v,int l,int r){
    if (l==r){
        t[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=max(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return max(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}

void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i];
    build(1,1,m);
    int q;cin>>q;
    for (int it=1;it<=q;it++){
        int x1,y1,x2,y2,k;cin>>x1>>y1>>x2>>y2>>k;
        if (x1%k!=x2%k || y1%k!=y2%k){
            cout<<"NO\n";
            continue;
        }
        if (y1>y2){
            swap(y1,y2);
            swap(x1,x2);
        }
        int x=n-(n+k-x1%k)%k;
        if (get(1,1,m,y1,y2)>=x){
            cout<<"NO\n";
//            cout<<get(1,1,m,y1,y2)<<endl;
            continue;
        }
        cout<<"YES\n";
    }

}
int32_t main() {
//    freopen("5.034.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
4 3 2000
1 2 100
2 3 1000
2 4 1000
1.27
3,16,27,24,23,46
**/