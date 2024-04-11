#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=200010;
const ll mod=998244353;
int a[N],b[N];
ll pref[N];
struct node{
    ll mn,mx;
    node(){
        mn=1000000000000000000ll;
        mx=-mn;
    }
};
node t[N*4];
node Merge(node A,node B){
    node C;
    C.mn=min(A.mn,B.mn);
    C.mx=max(A.mx,B.mx);
    return C;
}
void build(int v,int l,int r){
    if (l==r){
        t[v].mn=t[v].mx=pref[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=Merge(t[v+v],t[v+v+1]);

}
node empt;
node get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return empt;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return Merge(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++){
        pref[i]=pref[i-1]+b[i]-a[i];
    }
    build(1,1,n);
    for (int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        node cur=get(1,1,n,l,r);
        cur.mn-=pref[l-1];
        cur.mx-=pref[l-1];
        if (cur.mn<0 || pref[r]-pref[l-1]!=0){
            cout<<-1<<endl;
        } else cout<<cur.mx<<endl;
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
8
1 104
220 909
380 378
521 641
765 184
802 969
897 729
992 887
*/