//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=200010;
const int A=10000010;
int comp[A];
int p[A];
int a[N];
pair<int,int>dp[N][22];
int last[A];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]=comp[x];
//        cout<<a[i]<<" ";
    }
//    cout<<endl;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j]={n+1,1};
        }
    }
    dp[1][0]={1,-1};
    last[a[1]]=1;
    for (int i=2;i<=n;i++){
        for (int j=0;j<=k;j++){
            if (dp[i-1][j].second==1) continue;
//            cout<<i-1<<" "<<j<<" "<<dp[i-1][j].first<<" "<<dp[i-1][j].second<<endl;
            int l=-dp[i-1][j].second;
            dp[i][j]=min(dp[i][j],{dp[i-1][j].first+1,-i});
            int nj=j;
            if (last[a[i]]>=l) nj++;
            dp[i][nj]=min(dp[i][nj],dp[i-1][j]);
        }
        last[a[i]]=i;
    }
    for (int i=1;i<=n;i++) last[a[i]]=0;
    int res=n;
    for (int i=0;i<=k;i++) res=min(res,dp[n][i].first);
    cout<<res<<endl;


}
int main()
{
    for (int i=2;i<A;i++) p[i]=i;
    comp[1]=1;
    for (int i=2;i<A;i++){
        if (p[i]==i){
            for (int j=i+i;j<A;j+=i) p[j]=i;
        }
        int cnt=0;
        int x=i;
        while (x%p[i]==0){
            x/=p[i];
            cnt++;
        }
        comp[i]=comp[x];
        if (cnt%2) comp[i]*=p[i];
    }

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
1
11 4
6 2 2 8 9 1 3 6 3 9 7


**/