#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
int pref[N][2];
int a[N];
int b[N];
int c[N];
const int L=20;
int dp[L][N];
int n;
void solve(){
    cin>>n;
    for (int i=1;i<=n;++i){
        char c;cin>>c;
        if (c=='0') a[i]=0;
        else if (c=='1') a[i]=1;
        else a[i]=2;
        pref[i][0]=pref[i-1][0];
        pref[i][1]=pref[i-1][1];
        if (c!='0') pref[i][1]++;
        if (c!='1') pref[i][0]++;
    }
    for (int i=n;i>=1;i--){
        if (a[i]!=1) b[i]=b[i+1]+1;
        if (a[i]!=0) c[i]=c[i+1]+1;
    }
    for (int i=1;i<=n;i++){
        dp[0][i]=max(b[i],c[i]);
    }
    for (int i=1;i<L;i++){
        for (int j=1;j<=n;j++){
            if (j+(1<<i)-1<=n) dp[i][j]=max(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
            else dp[i][j]=N;
        }
    }
    int cnt=0;
    for (int x=1;x<=n;x++){
        int pos=1;
        int res=0;
        for (;pos<=n;){
            for (int i=19;i>=0;i--){
                cnt++;
                if (dp[i][pos]<x) pos+=(1<<i);
            }
            pos+=x;
            res+=(pos<=n+1);
        }
        cout<<res<<" ";
    }
    cout<<endl;
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