#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int lst[201][31];
char s[201];
int dp[201][201];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=0;i<=25;i++) lst[0][i]=-1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=25;j++) lst[i][j]=lst[i-1][j];
        lst[i][s[i]-'a']=i;
    }
    for (int i=1;i<=n;i++) dp[1][i]=1;
    for (int len=2;len<=n;len++){
        for (int i=len;i<=n;i++){
            for (int j=0;j<=25;j++){
                if (lst[i-1][j]!=-1){
                    dp[len][i]+=dp[len-1][lst[i-1][j]];
                    dp[len][i]=min(dp[len][i],1000000000000ll);
                }
            }
        }
    }
    ll res=0ll;
    for (int len=n;len>=1;len--){
        int cur=0;
        for (int j=0;j<=25;j++){
            if (lst[n][j]!=-1){
                cur+=dp[len][lst[n][j]];
            }
        }
        if (k>cur){
            k-=cur;
            res+=cur*(n-len);
        } else {
            res+=k*(n-len);
            k=0;
        }
    }
    if (k){
        k--;
        res+=n;
    }
    if (k) cout<<-1;
    else cout<<res;
    return 0;
}