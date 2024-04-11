#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int dp[201][201][811];
pair<pair<int,int>,int> pr[201][201][811];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a,b;cin>>a>>b;
    for (int i=0;i<=a.size();i++) for (int j=0;j<=b.size();j++) for (int t=0;t<=800;t++) dp[i][j][t]=1000000001,pr[i][j][t]={{-1,-1},-1};
    dp[0][0][0]=0;
    for (int i=0;i<=a.size();i++){
        for (int j=0;j<=b.size();j++){
            for (int t=0;t<=800;t++){
                // (
                int nxti=i;
                int nxtj=j;
                if (i<a.size() && a[i]=='(') nxti++;
                if (j<b.size() && b[j]=='(') nxtj++;
                if (dp[nxti][nxtj][t+1]>dp[i][j][t]+1){
                    dp[nxti][nxtj][t+1]=dp[i][j][t]+1;
                    pr[nxti][nxtj][t+1]={{i,j},t};
                }
                // )
                if (t>0){
                    nxti=i;
                    nxtj=j;
                    if (i<a.size() && a[i]==')') nxti++;
                    if (j<b.size() && b[j]==')') nxtj++;
                    //if (i==1 && j==2 && t==2) cout<<nxti<<" "<<nxtj<<endl;

                    if (dp[nxti][nxtj][t-1]>dp[i][j][t]+1){
                        dp[nxti][nxtj][t-1]=dp[i][j][t]+1;
                        pr[nxti][nxtj][t-1]={{i,j},t};
                    }
                }
            }
            for (int t=800;t>=0;t--){
                // (
                int nxti=i;
                int nxtj=j;
                if (i<a.size() && a[i]=='(') nxti++;
                if (j<b.size() && b[j]=='(') nxtj++;
                if (dp[nxti][nxtj][t+1]>dp[i][j][t]+1){
                    dp[nxti][nxtj][t+1]=dp[i][j][t]+1;
                    pr[nxti][nxtj][t+1]={{i,j},t};
                }
                // )
                if (t>0){
                    nxti=i;
                    nxtj=j;
                    if (i<a.size() && a[i]==')') nxti++;
                    if (j<b.size() && b[j]==')') nxtj++;
                    //if (i==1 && j==2 && t==2) cout<<nxti<<" "<<nxtj<<endl;

                    if (dp[nxti][nxtj][t-1]>dp[i][j][t]+1){
                        dp[nxti][nxtj][t-1]=dp[i][j][t]+1;
                        pr[nxti][nxtj][t-1]={{i,j},t};
                    }
                }
            }
        }
    }
    int i=a.size();
    int j=b.size();
    int t=0;
    string ans="";
    int res=dp[i][j][t];
   // cout<<res<<endl;
    while (i>0 || j>0 || t>0){
        pair<pair<int,int>,int>nxt=pr[i][j][t];
        int nxti=nxt.first.first;
        int nxtj=nxt.first.second;
        int nxtt=nxt.second;
        if (nxtt<t) ans+='(';
        else ans+=')';
        i=nxti;
        j=nxtj;
        t=nxtt;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}