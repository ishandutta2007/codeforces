#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=35010;
const int K=110;
int dp[N][K];
const ll inf=1e9;
int a[N];
int last[N],l[N];
int t[K][N*4];
int w[K][N*4];

void build(int v,int l,int r){
    for (int i=0;i<K;i++){
        t[i][v]=inf;
        w[i][v]=0;
    }
    if (l==r) return;
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
}
void push(int v,int j){
    t[j][v+v]+=w[j][v];
    t[j][v+v+1]+=w[j][v];
    w[j][v+v]+=w[j][v];
    w[j][v+v+1]+=w[j][v];
    w[j][v]=0;
}
void upd(int v,int l,int r,int L,int R,int x,int j){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[j][v]+=x;
        w[j][v]+=x;
        return;
    }
    push(v,j);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x,j);
    upd(v+v+1,m+1,r,L,R,x,j);
    t[j][v]=min(t[j][v+v],t[j][v+v+1]);
}
int get(int v,int l,int r,int L,int R,int j){
    if (l>R || r<L) return inf;
    if (l>=L && r<=R) return t[j][v];
    push(v,j);
    int m=(l+r)/2;
    return min(get(v+v,l,m,L,R,j),get(v+v+1,m+1,r,L,R,j));
}
void solve(){
    for (int i=0;i<N;i++){
        for (int j=0;j<K;j++){
            dp[i][j]=inf;
        }
    }
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        l[i]=last[a[i]];
        last[a[i]]=i;
    }
    build(1,0,n);
    dp[0][0]=0;
    upd(1,0,n,0,0,-inf,0);
//    cout<<get(1,0,n,0,0,0)<<endl;
    for (int i=1;i<=n;i++){
        if (l[i]) {
            for (int j=0;j<=k;j++) upd(1,0,n,0,l[i]-1,i-l[i],j);
        }
        for (int j=1;j<=k;j++){
            dp[i][j]=get(1,0,n,0,i-1,j-1);
            upd(1,0,n,i,i,dp[i][j]-inf,j);
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    cout<<dp[n][k]<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}