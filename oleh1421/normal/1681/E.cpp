//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
const ll inf=10000000000001ll;
struct node{
    ll d[2][2];
    node(){
        d[0][0]=d[1][1]=0;
        d[0][1]=d[1][0]=inf;
    }
};
node t[N*4];
node Merge(node A,node B){
    node C;

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            C.d[i][j]=inf;
            for (int t=0;t<2;t++){
                C.d[i][j]=min(C.d[i][j],A.d[i][t]+B.d[t][j]);
            }
        }
    }
    return C;
}
ll dx[N][2],dy[N][2];
void build(int v,int l,int r){
    if (l>r) return;
    if (l==r){
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                int x=dx[l][i];
                int y=dy[l][i];
                if (i) y++;
                else x++;
                t[v].d[i][j]=abs(x-dx[l+1][j])+abs(y-dy[l+1][j])+1;
            }
        }
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                t[v].d[i][j]=min(t[v].d[i][j],abs(dx[l][i]-dx[l][i^1])+abs(dy[l][i]-dy[l][i^1])+t[v].d[i^1][j]);
            }
        }
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
node get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return node();
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return Merge(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<n;i++){
        cin>>dx[i][0]>>dy[i][0]>>dx[i][1]>>dy[i][1];
    }
    if (n>2) build(1,1,n-2);
    int m;cin>>m;
    for (int it=1;it<=m;it++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        int l=max(x1,y1);
        int r=max(x2,y2);
        if (l>r){
            swap(x1,x2);
            swap(y1,y2);
            swap(l,r);
        }
        if (l==r){
            cout<<abs(x1-x2)+abs(y1-y2)<<endl;
            continue;
        }
        node cur=node();
        if (l<=r-2) cur=get(1,1,n-2,l,r-2);
        ll res=inf;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                res=min(res,abs(dx[l][i]-x1)+abs(dy[l][i]-y1)+abs(dx[r-1][j]-x2+1-j)+abs(dy[r-1][j]+j-y2)+1+cur.d[i][j]);
            }
        }
        cout<<res<<endl;
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
5
1 1 1 1
2 1 2 2
3 2 1 3
4 1 1 4
1
1 3 5 4
*/