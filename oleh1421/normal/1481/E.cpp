//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
int a[N];
int cnt[N];
int l[N];
int r[N];
vector<pair<int,int> >g[N];
int dp[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        if (!l[a[i]]) l[a[i]]=i;
        r[a[i]]=i;
        cnt[a[i]]++;
    }
    for (int i=1;i<=n;i++){
        if (cnt[i]){
            g[l[i]].push_back({r[i]+1,cnt[i]});
        }
    }

    for (int i=1;i<=n;i++){
        g[i].push_back({n+1,cnt[a[i]]});
        cnt[a[i]]--;
    }
    dp[0]=0;
    for (int i=0;i<=n;i++){
        dp[i+1]=max(dp[i+1],dp[i]);
        for (auto cur:g[i]){
            dp[cur.first]=max(dp[cur.first],dp[i]+cur.second);
        }
    }

    cout<<n-dp[n+1]<<endl;

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
/*
5
2 2 1 3 3
*/