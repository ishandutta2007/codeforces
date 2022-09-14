#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007ll;
#define endl '\n'
int dp[300001];
int mx[31];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    int res=0;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        int x=(c-'a');
        dp[i]=1;
        for (int j=x+1;j<=25;j++) dp[i]=max(dp[i],mx[j]+1);
        mx[x]=max(dp[i],mx[x]);
        res=max(res,dp[i]);
    }
    if (res>2) {
        cout<<"NO";
    }else {
        cout<<"YES\n";
        for (int i=1;i<=n;i++) cout<<dp[i]-1;
    }
    return 0;
}