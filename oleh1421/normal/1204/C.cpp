#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int a[201][201];
int last[111];
int last1[111];
int p[1000001];
int dp[1000011];
int pr[1000011];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            a[i][j]=1;
            if (c=='0') a[i][j]+=100000;
            if (i==j) a[i][j]=0;
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    int m;cin>>m;
    for (int i=1;i<=m;i++) cin>>p[i];
    for (int i=1;i<=m;i++) dp[i]=100000001;
    dp[1]=1;
    last[p[1]]=1;
    for (int i=2;i<=m;i++){
        last1[p[i]]=last[p[i]];
        last[p[i]]=i;
        for (int j=1;j<=n;j++){
            if (last1[j] && a[j][p[i]]==i-last1[j]){
                if (dp[i]>dp[last1[j]]+1){
                    dp[i]=dp[last1[j]]+1;
                    pr[i]=last1[j];
                }
            }
            if (last[j] && a[j][p[i]]==i-last[j]){
                if (dp[i]>dp[last[j]]+1){
                    dp[i]=dp[last[j]]+1;
                    pr[i]=last[j];
                }
            }
        }
    }
    cout<<dp[m]<<endl;
    vector<int>ans;
    int cur=m;
    while (cur){
        ans.push_back(cur);
        cur=pr[cur];
    }
    reverse(ans.begin(),ans.end());
    for (auto i:ans) cout<<p[i]<<" ";
    return 0;
}