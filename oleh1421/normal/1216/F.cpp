#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int long long
using namespace std;
int a[300001];
ll dp[1000001];
ll w[1000001];
ll t[1000001];
void push(int v){
     t[v+v]=min(t[v+v],w[v]);
     t[v+v+1]=min(t[v+v+1],w[v]);
     w[v+v]=min(w[v+v],w[v]);
     w[v+v+1]=min(w[v+v+1],w[v]);
     w[v]=1000000000001ll;
}
void upd(int v,int l,int r,int L,int R,ll x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        w[v]=min(w[v],x);
        t[v]=min(t[v],x);
        return;
    }
    int m=(l+r)/2;
    push(v);
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=min(t[v+v],t[v+v+1]);
}
ll get(int v,int l,int r,int L,int R){
   if (l>R || r<L) return 1000000000001ll;
   if (l>=L && r<=R) return t[v];
   int m=(l+r)/2;
   push(v);
   return min(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i=0;i<=1000000;i++) dp[i]=1000000000001ll,w[i]=1000000000001ll,t[i]=1000000000001ll;
    int n,k;cin>>n>>k;
    string s;cin>>s;
    for (int i=0;i<n;i++) a[i+1]=(s[i]-'0');
    dp[0]=0ll;
    for (int i=1;i<=n;i++){
        if (a[i]){

            ll cur=1000000000001ll;
            if (i-k-1<=0) cur=i*1ll;
            else cur=get(1,1,n,max(1,i-k)-1,i)+i*1ll;
            upd(1,1,n,i,min(n,i+k),cur);
        } else {
            upd(1,1,n,i,i,dp[i-1]+i*1ll);
        }
        dp[i]=get(1,1,n,i,i);
    }
    cout<<dp[n];
    return 0;
}