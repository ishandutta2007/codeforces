#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b){
     if (a.second<0 && b.second>=0) return false;
     if (a.second>=0 && b.second<0) return true;
     if (a.second>=0 && b.second>=0) return a.first<b.first;
     return (a.first+a.second>b.first+b.second);
}
int dp[301][60011];
int a[1111];
int b[1111];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,r;cin>>n>>r;
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=0;
    for (auto i:v){
        a[++cnt]=i.first;
        b[cnt]=i.second;
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=60000;j++) dp[i][j]=-1000000001;
    dp[0][r]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<i;j++){
            for (int t=a[i];t+b[i]<=60000 && t<=60000;t++){
                if (t+b[i]>=0){
                    dp[i][t+b[i]]=max(dp[i][t+b[i]],dp[j][t]+1);
                }
            }
        }
    }
    int res=0;
    for (int i=0;i<=n;i++) for (int j=0;j<=60000;j++) res=max(res,dp[i][j]);
    cout<<res;
    return 0;
}

/*
20 30000
636 -231
284 -28
154 -175
90 -127
277 159
272 -87
136 -253
233 181
488 275
56 -90
280 132
340 12
151 117
150 -232
92 -284
328 -113
248 -53
99 211
609 166
13 -35
*/