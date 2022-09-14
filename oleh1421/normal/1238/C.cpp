#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int h,n;
int p[300001];
int dp[300001];
void solve(){
    cin>>h>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    int cnt=0;
    //p[++n]=0;
    for (int i=0;i<=n;i++) dp[i]=1000000001;
    dp[1]=0;
    dp[2]=1;
    for (int i=3;i<=n;i++){
         dp[i]=dp[i-1]+1;
         if (p[i-1]-p[i]==1) dp[i]=min(dp[i],dp[i-2]);
    }
    int res=dp[n];
    if (p[n]==1) res=min(res,dp[n-1]);
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int x[100001];
int y[100001];
int minx[100001];
int maxx[100001];
int n,k;
int f(int l,int r,int j){
    int l1=l+(k-l%k+j%k)%k;
    int r1=r-(k+r%k-j%k)%k;
    return (r1-l1)/k+(l1-l>0)+(r-r1>0);
}
int main()
{
    //freopen("monument.in","r",stdin);
    //freopen("monument.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i],x[i]++,y[i]++;
    for (int i=1;i<=n;i++){
        int nxt=i+1;
        if (nxt>n) nxt=1;
        if (x[i]==x[nxt]){
            for (int j=min(y[i],y[nxt]);j<max(y[i],y[nxt]);j++){
                if (!minx[j] || minx[j]>x[i]) minx[j]=x[i];
                if (maxx[j]<x[i]) maxx[j]=x[i];
            }
        }
    }
    ll sum=0ll;
        //cout<<i<<endl;
    vector<int>v;
    for (int j=0;j<=100000;j++){
        if (!minx[j]) continue;
        if ((maxx[j]-minx[j])<k) sum++;
        else if ((maxx[j]-minx[j])%k==0) v.push_back(minx[j]%k),sum+=(maxx[j]-minx[j])/k;
        else

        cur+=f(minx[j],maxx[j],j);
    }
    cout<<sum;
    return 0;
}

*/