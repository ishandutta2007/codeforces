#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=300010;
int minx[N];
int maxx[N];
int a[N*2];
int last[N];
int t[N*9];
void upd(int v,int l,int r,int pos,int x){
    if (l>pos || r<pos) return;
    if (l==r){
        t[v]=x;
        return;
    }
    int m=(l+r)/2;
    upd(v+v,l,m,pos,x);
    upd(v+v+1,m+1,r,pos,x);
    t[v]=t[v+v]+t[v+v+1];
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return get(v+v,l,m,L,R)+get(v+v+1,m+1,r,L,R);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i+n];
    for (int i=1;i<=n;i++) minx[i]=maxx[i]=i;
    for (int i=1;i<=m;i++) minx[a[i+n]]=1;
    for (int i=1;i<=n;i++) a[i]=n-i+1;
    for (int i=1;i<=n+m;i++){
        if (!last[a[i]]){
            upd(1,1,n+m,i,1);
            last[a[i]]=i;
            continue;
        }
        maxx[a[i]]=max(maxx[a[i]],get(1,1,n+m,last[a[i]],i-1));
        upd(1,1,n+m,last[a[i]],0);
        last[a[i]]=i;
        upd(1,1,n+m,last[a[i]],1);
    }
    for (int i=1;i<=n;i++){
        maxx[i]=max(maxx[i],get(1,1,n+m,last[i],n+m));
    }
    for (int i=1;i<=n;i++) cout<<minx[i]<<" "<<maxx[i]<<endl;
    return 0;
}