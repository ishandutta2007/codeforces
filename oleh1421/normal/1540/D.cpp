//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100100;
const int K=100;
const ll mod=998244353;
vector<int>block[N/K+5];
int b[N];
int n;
int C;
int t[N*4];
void build(int v,int l,int r){
    if (t[v]==r-l+1) return;
    t[v]=r-l+1;
    if (l==r) return;
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
}
void upd(int v,int l,int r,int pos,int x){
    t[v]+=x;
    if (l==r) return;
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos,x);
    else upd(v+v+1,m+1,r,pos,x);
}
int Find(int v,int l,int r,int x){
    if (l==r) return l;
    int m=(l+r)/2;
    if (t[v+v]>=x) return Find(v+v,l,m,x);
    else return Find(v+v+1,m+1,r,x-t[v+v]);
}
void upd_block(int ind){
    build(1,1,n);
    int L=(ind-1)*K+1;
    int R=min(n,ind*K);
    block[ind].clear();
    for (int i=L;i<=R;i++){
        int cur=Find(1,1,n,b[i]);
        upd(1,1,n,cur,1);
        block[ind].push_back(cur);
    }
    sort(block[ind].begin(),block[ind].end());
}
int get(int p){
    int ind=(p+K-1)/K;
    int L=(ind-1)*K+1;
    int R=min(n,ind*K);
    int cur=b[p];
    for (int i=p+1;i<=R;i++) cur+=(cur>=b[i]);
    for (int i=ind+1;i<=C;i++) {
        cur+=upper_bound(block[i].begin(),block[i].end(),cur)-block[i].begin();
    }
    return cur;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) b[i]=i;
    C=(n+K-1)/K;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        b[i]=i-x;
    }
    for (int i=1;i<=C;i++){
        upd_block(i);
    }
    int q;cin>>q;
    for (int i=1;i<=q;i++){
        int type;cin>>type;
        if (type==1){
            int p,x;cin>>p>>x;
            b[p]=p-x;
            upd_block((p+K-1)/K);
        } else {
            int x;cin>>x;
            cout<<get(x)<<endl;
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
//1 3 3 4
//0 1 2 3