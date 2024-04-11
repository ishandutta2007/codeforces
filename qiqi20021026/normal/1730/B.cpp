#include<bits/stdc++.h>

using namespace std;

#define N 300'000
#define INF 0x3f3f3f3f
const double eps=1e-6;
int n,x[N],t[N],pre[N],suf[N],p[N],x_[N],t_[N];

void solve(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x_[i];
        p[i]=i;
    }
    for (int i=1;i<=n;++i){
        cin>>t_[i];
    }
    sort(p+1,p+n+1,[&](int i,int j){return x_[i]<x_[j];});
    for (int i=1;i<=n;++i) x[i]=x_[p[i]],t[i]=t_[p[i]];
    pre[0]=-INF;
    for (int i=1;i<=n;++i){
        pre[i]=max(pre[i-1],t[i]-x[i]);
        // cout<<pre[i]<<' ';
    }
    // cout<<'\n';
    suf[n+1]=-INF;
    for (int i=n;i;--i){
        suf[i]=max(suf[i+1],t[i]+x[i]);
        // cout<<suf[i]<<' ';
    }
    // cout<<'\n';
    for (int i=1;i<n;++i){
        int l=x[i],r=x[i+1];
        //s+pre[i]==suf[i+1]-s
        double s=(suf[i+1]-pre[i])/2.0;
        if (s<l+eps){
            cout<<l<<'\n'; return;
        }
        if (s>=l-eps&&s<=r+eps){
            cout<<s<<'\n'; return;
        }
    }
    cout<<x[n]<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout<<setiosflags(ios::fixed)<<setprecision(15);
    int T; cin>>T;
    while (T--) solve();
}