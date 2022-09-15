#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char b[200001];
char a[3];
char g(char s1,char s2){
     for (int i=0;i<3;i++) if (a[i]!=s1 && a[i]!=s2) return a[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a[0]='R';
    a[1]='G';
    a[2]='B';
    int n;cin>>n;
    pair<int,int>dp[n+1][3];
    string s;cin>>s;
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            dp[i][j]={n,0};
        }
    }
    if (s[0]==a[0]) dp[0][0]={0,0};
    if (s[0]==a[1]) dp[0][1]={0,0};
    if (s[0]==a[2]) dp[0][2]={0,0};
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            for (int k=0;k<3;k++){
                if (k==j) continue;
                if (i+1<n){ dp[i+1][k]=min(dp[i+1][k],{dp[i][j].first+(a[k]!=s[i+1]),j});
                //cout<<i+1<<" "<<k<<" "<<dp[i+1][k].first<<" "<<dp[i+1][k].second<<endl;
                }
            }
        }
    }
    int k;
    if (dp[n-1][0].first<=dp[n-1][1].first && dp[n-1][0].first<=dp[n-1][2].first){
         k=0;
    } else if (dp[n-1][1].first<=dp[n-1][0].first && dp[n-1][1].first<=dp[n-1][2].first){
       k=1;
    }else k=2;
     //cout<<k<<" "<<dp[n-1][k].first<<endl;
        string str="";
        cout<<dp[n-1][k].first<<endl;
        for (int i=n-1;i>=0;i--){
            str+=a[k];
            k=dp[i][k].second;
        }
        reverse(str.begin(),str.end());
        cout<<str;
    return 0;
}