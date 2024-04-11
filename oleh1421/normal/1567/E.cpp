#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=200010;
const int T_SZ=3000010;
const ll mod=1000000007;
int arr[N];
int a[N];
struct node{
    int lft,rght;
    bool full;
    ll ans;
    node(){
        lft=rght=full=ans=0;
    }
    node(int x){
        lft=rght=full=ans=x;
    }
};
node Merge(node A,node B){
    node C;
    C.full=(A.full&B.full);
    C.lft=A.lft;
    if (A.full) C.lft+=B.lft;
    C.rght=B.rght;
    if (B.full) C.rght+=A.rght;
    C.ans=A.ans+B.ans-(ll)(A.rght+1ll)*(A.rght)/2ll-(ll)(B.lft+1ll)*B.lft/2ll+(ll)(A.rght+B.lft+1ll)*(A.rght+B.lft)/2ll;
    return C;
}
node t[524288+10];
void build(int v,int l,int r){
    if (l==r){
        t[v]=node(arr[l]);
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
void upd(int v,int l,int r,int pos){
    if (l==r){
        t[v]=node(arr[l]);
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos);
    else upd(v+v+1,m+1,r,pos);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
node get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return node(0);
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return Merge(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){

    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (n==1){
        for (int i=1;i<=q;i++){
            int type,x,y;cin>>type>>x>>y;
            if (type==2) cout<<1<<endl;
        }
        return;
    }
    for (int i=1;i<n;i++){
        arr[i]=(a[i]<=a[i+1]);
    }
    build(1,1,n-1);
    for (int i=1;i<=q;i++){
        int type,x,y;cin>>type>>x>>y;
        if (type==1){
            a[x]=y;
            if (x>1) {
                arr[x-1]=(a[x-1]<=a[x]);
                upd(1,1,n-1,x-1);
            }
            if (x<n) {
                arr[x]=(a[x]<=a[x+1]);
                upd(1,1,n-1,x);
            }
        } else {
            cout<<get(1,1,n-1,x,y-1).ans+y-x+1<<endl;
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

//0 2
//-1 3
//1 3
//0 4
/*
8
1 104
220 909
380 378
521 641
765 184
802 969
897 729
992 887

C - centroid

5
0 0 -1 -1 1
*/