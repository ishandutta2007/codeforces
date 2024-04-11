//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=200010;
const ll mod=998244353;
const ll inf=2000000000000000000;
int a[N];
int cnt[N];
//int cnt1[N];
vector<int>g[N];
int pref[N];
const int K=1000;
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) g[i].push_back(0);
    for (int i=1;i<=n;i++) cin>>a[i],g[a[i]].push_back(i);
    for (int i=1;i<=n;i++) g[i].push_back(n+1);
    int mx=0;
    for (int i=1;i<=n;i++){
        if (g[i].size()>g[mx].size()) mx=i;
    }

    for (int i=1;i<=n;i++) pref[i]=pref[i-1]+(a[i]==mx);
    int ans=0;
    for (int i=1;i<=n;i++){
        if (g[i].size()<=K+2 || i==mx) continue;
        pref[0]=0;
        for (int j=1;j<=n;j++){
            if (a[j]==i) pref[j]=1;
            else if (a[j]==mx) pref[j]=-1;
            else pref[j]=0;
        }
        for (int j=1;j<=n;j++) pref[j]+=pref[j-1];
        for (int l=n;l>=0;l--) {
            int r=n+1;
            for (int j=19;j>=0;j--){
                if (r-(1<<j)>l && pref[r-(1<<j)]<pref[l]) r-=(1<<j);
            }
            r--;
            ans=max(ans,r-l);
            if (l<n) pref[l]=max(pref[l],pref[l+1]);
        }
    }
    for (int i=0;i<(int)g[mx].size()-1;i++){
        int l=g[mx][i]+1;
        int val=0;
        int cn=0;
        for (int r=l;r<g[mx][min((int)g[mx].size()-1,i+K+1)];r++){
            if (a[r]!=mx) val=max(val,++cnt[a[r]]);
            else cn++;
            if (val>=cn) ans=max(ans,r-l+1);
        }
        for (int r=l;r<g[mx][min((int)g[mx].size()-1,i+K+1)];r++){
            cnt[a[r]]=0;
        }
    }
    cout<<ans<<endl;
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
/**
5
1 2 1 3 1
**/