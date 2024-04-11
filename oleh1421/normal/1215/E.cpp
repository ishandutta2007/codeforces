#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[500001];
int s[400001][20];
int cnt[20];
ll sum[20];
ll f[20][20];
int mask1=0;
ll dp[2000000];
ll F(int mask){
    if (mask==mask1) return 0;
    if (dp[mask]!=-1) return dp[mask];
    vector<int>v;
    for (int j=0;j<20;j++){
        if ((mask&(1<<j))) v.push_back(j);
    }
    ll minx=100000000000000001ll;
    for (int i=0;i<20;i++){
        if (cnt[i]==0) continue;
        if (mask&(1<<i)) continue;
        ll cur=sum[i];
        for (auto j:v) cur-=f[i][j];
        minx=min(minx,F(mask^(1<<i))+cur);
    }
    return dp[mask]=minx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=0;i<=(1<<20);i++) dp[i]=-1;
    mask1=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]--;
        mask1|=(1<<a[i]);
        for (int j=0;j<20;j++) s[i][j]=s[i-1][j];
        s[i][a[i]]++;
        cnt[a[i]]++;
        sum[a[i]]+=(i-cnt[a[i]])*1ll;
        for (int j=0;j<20;j++){
            f[a[i]][j]+=s[i][j]*1ll;
        }
    }
    cout<<F(0);
    return 0;
}