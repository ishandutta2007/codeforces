#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'

const int N=300010;
const ll inf=1000000000000000001ll;
struct node{
    ll dp[2][2];
};
node t[N*4];
ll a[N];
node Merge(node A,node B){
    node C;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            C.dp[i][j]=max(A.dp[i][j],B.dp[i][j]);
            for (int t=0;t<2;t++){
                C.dp[i][j]=max(C.dp[i][j],A.dp[i][t]+B.dp[t^1][j]);
            }
        }
    }
    return C;
}
void build(int v,int l,int r){
    if (l>r) return;
    if (l==r){
        t[v].dp[0][0]=a[l];
        t[v].dp[1][1]=-a[l];
        t[v].dp[0][1]=t[v].dp[1][0]=-inf;
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
void upd(int v,int l,int r,int pos){
    if (l==r){
        t[v].dp[0][0]=a[l];
        t[v].dp[1][1]=-a[l];
        t[v].dp[0][1]=t[v].dp[1][0]=-inf;
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos);
    else upd(v+v+1,m+1,r,pos);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cout<<max(t[1].dp[0][0],t[1].dp[0][1])<<endl;
    for (int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        swap(a[l],a[r]);
        upd(1,1,n,l);
        upd(1,1,n,r);
        cout<<max(t[1].dp[0][0],t[1].dp[0][1])<<endl;

    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}