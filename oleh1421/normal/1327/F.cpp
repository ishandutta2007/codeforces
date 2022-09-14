//#pragma GCC opitmize ("Ofast")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=600050;
const ll mod=998244353ll;
int a[N];
int l[N];
int r[N];
int x[N];
int w[N];
ll dp[N];
ll pref[N];
int mx[N];
int n,m,k;
int f[N];
vector<int>g[N];
ll solve(int pos){
//    cout<<"xxx: "<<pos<<endl;
    for (int i=0;i<=n;i++) a[i]=f[i]=0,g[i].clear();
    for (int i=1;i<=m;i++){
        if (x[i]&(1<<pos)){
            a[l[i]]++;
            a[r[i]+1]--;
        }
    }
    for (int i=1;i<=n;i++) a[i]+=a[i-1];
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (!a[i]) v.push_back(i);
    }
    vector<pair<int,int> >u;
    for (int i=1;i<=n;i++){
        f[i]=f[i-1];
        while (f[i]<v.size() && v[f[i]]<i) f[i]++;
    }
    f[n+1]=v.size();
    for (int i=1;i<=m;i++){
        if (x[i]&(1<<pos)) continue;
        int curL=f[l[i]];
        int curR=f[r[i]+1]-1;
        if (curL>curR) return 0ll;
//        if (pos==2) cout<<"LR: "<<curL<<" "<<curR<<endl;
        g[curR].push_back(curL);
    }
    for (int i=0;i<=v.size();i++){
        for (auto L:g[i]) u.push_back({i,L});
    }
    if (u.empty()){
        ll res=1ll;
        for (int i=0;i<v.size();i++) res=(res+res)%mod;
        return res;
    }
//    cout<<"OK\n";
    int sz=v.size();
    for (int i=0;i<=n;i++) pref[i]=dp[i]=mx[i]=0ll;
    mx[0]=u[0].second;
    for (int i=1;i<u.size();i++){
        mx[i]=max(mx[i-1],u[i].second);
    }
    dp[0]=1;
    pref[0]=1;
//    cout<<"OK\n";
    int ind1=0;
    for (int i=1;i<=sz+1;i++){
        pair<int,int>fnd={i-1,-1};
        while (ind1<u.size() && u[ind1].first<i-1) ind1++;
        int ind=ind1-1;
        dp[i]=pref[i-1];
        if (ind!=-1) dp[i]+=mod-pref[mx[ind]];
        dp[i]%=mod;
        pref[i]=(pref[i-1]+dp[i])%mod;
    }
    return dp[sz+1];

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>m;
    for (int i=1;i<=m;i++){
        cin>>l[i]>>r[i]>>x[i];
    }
    ll res=1ll;
    for (int i=0;i<k;i++){
        res*=solve(i);
        res%=mod;
    }
    cout<<res;
    return 0;
}
/*
1 4 1
1 1 5
*/