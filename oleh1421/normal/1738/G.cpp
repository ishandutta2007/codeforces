#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=1010;
const int TSZ=2e7;
const ll inf=1e18;
int need[N][N];
int ans[N][N];
int n,k;
struct BIT{
    int t[N*N];
    void upd(int pos,int x){
        for (;pos<=n+1;pos|=pos+1) t[pos]=max(t[pos],x);
    }
    int get(int pos){
        int mx=0;
        for (;pos>=0;pos&=pos+1,pos--) mx=max(mx,t[pos]);
        return mx;
    }
    void clr(){
        for (int i=0;i<=n+1;i++){
            t[i]=0;
        }
    }
};
BIT T;
struct SegTree{
    int TOT=1;
    int root[N];
    int t[TSZ];
    int L[TSZ];
    int R[TSZ];

    int copy_v(int v){
        TOT++;
        t[TOT]=t[v];
        L[TOT]=L[v];
        R[TOT]=R[v];
        return TOT;
    }
    void upd(int v,int l,int r,int pos,int x){
        if (l==r){
            t[v]=max(t[v],x);
            return;
        }
        int m=(l+r)/2;
        if (pos<=m){
            L[v]=copy_v(L[v]);
            upd(L[v],l,m,pos,x);
        } else {
            R[v]=copy_v(R[v]);
            upd(R[v],m+1,r,pos,x);
        }
        t[v]=max(t[L[v]],t[R[v]]);
    }
    int get(int v,int l,int r,int qL,int qR){
        if (l>qR || r<qL || !v) return 0;
        if (l>=qL && r<=qR) return t[v];
        int m=(l+r)/2;
        return max(get(L[v],l,m,qL,qR),get(R[v],m+1,r,qL,qR));
    }
    void clr(){
        while (TOT){
            L[TOT]=R[TOT]=t[TOT]=0;
            TOT--;
        }
        TOT=1;
    }

};
SegTree TT;
void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            need[i][j]=(c-'0');
            need[i][j]^=1;
            ans[i][j]=0;
        }
    }
    vector<pair<int,int> >A;
    for (int i=1;i<=n;i++){
        for (int j=n;j>=1;j--){
            A.push_back({j,need[i][j]});
        }
    }

    TT.clr();
    vector<int>dp(n*n,0);
    vector<int>root(n*n+1,0);
    root[n*n]=1;
    for (int i=n*n-1;i>=0;i--){
        root[i]=TT.copy_v(root[i+1]);
        if (A[i].second){
            dp[i]=TT.get(root[i],1,n,A[i].first+1,n)+1;
            TT.upd(root[i],1,n,A[i].first,dp[i]);
        }
    }
    if (TT.t[root[0]]>=k){
        TT.clr();
        cout<<"NO\n";
        return;
    }
    T.clr();
    vector<int>take;

    for (int i=0;i<n*n;i++){
        int val=T.get(A[i].first-1)+1;
        if (val+TT.get(root[i+1],1,n,A[i].first+1,n)>=k) {
            continue;
        }
        if (!A[i].second) take.push_back(i);
        T.upd(A[i].first,val);
    }
    int cnt=0;
    for (int i=0;i<n*n;i++){
        if (A[i].second) {
            take.push_back(i);
            cnt++;
        }
    }
    if (cnt>n*n-(n-k+1)*(n-k+1)){
        cout<<"NO\n";
        return;
    }
    reverse(take.begin(),take.end());
    T.clr();
    TT.clr();


    if (take.size()<n*n-(n-k+1)*(n-k+1)){
        cout<<"NO\n";
        return;
    }
    while (take.size()>n*n-(n-k+1)*(n-k+1)) take.pop_back();
    for (int i:take){
        ans[i/n+1][n-i%n]=1;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) cout<<ans[i][j];
        cout<<'\n';
    }





}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}