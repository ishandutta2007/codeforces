#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-8
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long n,lis[100005],dp[100005][2];
string s[100005];

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    For(i,0,n) cin>>lis[i];
    For(i,0,n) cin>>s[i];
    reset(dp,-1);
    dp[0][0]=0;
    dp[0][1]=lis[0];
    For(i,1,n) {
        if(dp[i-1][0]!=-1) {
            int m = -1;
            int l1 = s[i-1].size();
            int l2 = s[i].size();
            For(j,0,min(l1,l2)) if(s[i][j]!=s[i-1][j]) {
                if(s[i][j]>s[i-1][j]) m=0;
                else m=-2;
                break;
            }
            if(m==0||m==-1&&l2>=l1) dp[i][0]=dp[i-1][0];
            m=-1;
            For(j,0,min(l1,l2)) if(s[i][l2-1-j]!=s[i-1][j]) {
                if(s[i][l2-1-j]>s[i-1][j]) m=0;
                else m=-2;
                break;
            }
            if(m==0||m==-1&&l2>=l1) dp[i][1] = lis[i] + dp[i-1][0];
            // if(m==0||m==-1&&l2>=l1) {
            //     if(dp[i][0]==-1) dp[i][1]=dp[i-1][0]+lis[i];
            //     else dp[i][0]=min(dp[i][0], dp[i-1][0]+lis[i]);
            // }
        }
        if(dp[i-1][1]!=-1) {
            int m = -1;
            int l1 = s[i-1].size();
            int l2 = s[i].size();
            For(j,0,min(l1,l2)) if(s[i][j]!=s[i-1][l1-1-j]) {
                if(s[i][j]>s[i-1][l1-1-j]) m=0;
                else m=-2;
                break;
            }
            if(m==0||m==-1&&l2>=l1) {
                // cout<<'a'<<endl;
                // cout<<dp[i][0]<<' '<<dp[i-1][1]<<endl;
                if(dp[i][0]==-1) dp[i][0]=dp[i-1][1];
                else dp[i][0]=min(dp[i][0],dp[i-1][1]);
            }
            m=-1;
            For(j,0,min(l1,l2)) if(s[i][l2-1-j]!=s[i-1][l1-1-j]) {
                if(s[i][l2-1-j]>s[i-1][l1-1-j]) m=0;
                else m=-2;
                break;
            }
            if(m==0||m==-1&&l2>=l1) {
                if(dp[i][1]==-1) dp[i][1]=dp[i-1][1]+lis[i];
                else dp[i][1]=min(dp[i][1], dp[i-1][1]+lis[i]);
            }
        }
    }
    if(dp[n-1][0]==-1) cout<<dp[n-1][1];
    else {
        if(dp[n-1][1]==-1) cout<<dp[n-1][0];
        else cout<<min(dp[n-1][1],dp[n-1][0]);
    }
}