#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int t[6000001];
int a[6000001];
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
    if (l>R || r<L) return -1000000001ll;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return max(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
ll ans[2000002];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,w;cin>>n>>w;
    for (int i=1;i<=n;i++){
        int m;cin>>m;
        for (int j=1;j<=m;j++) cin>>a[j];
        build(1,1,m);
        if (w<=m+m-1){
            for (int j=1;j<=w;j++){
                int r=min(j,m);
                int l=max(j-(w-m),1);
                int cur=get(1,1,m,l,r);
                if (j>m || (w-j)>=m) cur=max(cur,0);
                ans[j]+=cur;
                ans[j+1]-=cur;
            }
        } else {
            for (int j=1;j<m;j++){
                int r=j;
                int l=1;
                int cur=max(0,get(1,1,m,l,r));
                ans[j]+=cur;
                ans[j+1]-=cur;
            }
            for (int j=0;j<m-1;j++){
                int r=m;
                int l=m-j;
                int cur=max(0,get(1,1,m,l,r));
                int ind=w-j;
                ans[ind]+=cur;
                ans[ind+1]-=cur;
            }
            int cur=max(0,get(1,1,m,1,m));
            ans[m]+=cur;
            ans[w-m+2]-=cur;
        }
    }
    ll sum=0ll;
    for (int i=1;i<=w;i++){
        sum+=ans[i];
        cout<<sum<<" ";
    }
    return 0;
}