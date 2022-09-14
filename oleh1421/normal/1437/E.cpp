#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int inf=1000000001;
int a[N];
int b[N];
int L[N];
int dp[N];
vector<int>dq[N];
int pointer[N];
map<int,int>mp;
int t[N*4];
void build(int v,int l,int r){
    if (l==r){
        t[v]=inf;
        dq[l].clear();
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=min(t[v+v],t[v+v+1]);
}
void upd(int v,int l,int r,int pos){
//    cout<<"OK\n";
    if (l==r){
        if (dq[l].size()==pointer[l]) t[v]=inf;
        else t[v]=dq[l][pointer[l]];
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos);
    else upd(v+v+1,m+1,r,pos);
    t[v]=min(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return inf;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return min(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    for (int i=0;i<N*4;i++){
        t[i]=32;
    }
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i],a[i]-=i;
    for (int i=1;i<=k;i++) cin>>b[i];
    b[0]=0;
    b[k+1]=n+1;
    for (int i=1;i<=k+1;i++){
        for (int j=b[i-1]+1;j<=b[i];j++) L[j]=b[i-1];
    }
    dp[0]=0;
    a[0]=-inf;
    a[n+1]=inf*2;
    set<int>st;
    int Cn=0;
    for (int i=0;i<=n+1;i++) st.insert(a[i]);
    for (int x:st){
        mp[x]=++Cn;
    }
    for (int i=0;i<=n+1;i++) a[i]=mp[a[i]];
    build(1,1,Cn);
    dq[a[0]].push_back(0);
    upd(1,1,Cn,a[0]);
    for (int i=1;i<=n+1;i++){
        for (int j=L[i-1];j<L[i];j++){
            int cur=dp[j]-j;
            if (pointer[a[j]]<dq[a[j]].size() && dq[a[j]][pointer[a[j]]]==cur) {
                pointer[a[j]]++;
                upd(1,1,Cn,a[j]);
            }
        }
        dp[i]=get(1,1,Cn,1,a[i]);

//        for (int j=L[i];j<i;j++){
//            if (a[j]<=a[i]) dp[i]=min(dp[i],dp[j]-j);
//        }
        if (dp[i]!=inf){
            dp[i]+=i-1;
            int cur=dp[i]-i;
            while (dq[a[i]].size()>pointer[a[i]] && dq[a[i]].back()>cur) dq[a[i]].pop_back();
            dq[a[i]].push_back(cur);
            upd(1,1,Cn,a[i]);
        }



    }
    cout<<(dp[n+1]==inf ? -1 : dp[n+1])<<endl;
}
int main()
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
7
7 7 7 7 7 7 7
*/