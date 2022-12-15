#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long n,lis[500005],dp[500005],ans,ini;
string s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    ans=0;
    ini=0;
    For(i,0,n) cin>>lis[i];
    cin>>s;
    For(i,0,n) if(s[i]=='B') ini+=lis[i];
    if(s[0]=='A') dp[0]=lis[0];
    else dp[0]=(-lis[0]);
    ans=max(ans,dp[0]);
    //cout<<dp[0]<<' '<<-lis[0]<<endl;
    For(i,1,n)
    {
        if(s[i]=='A') dp[i]=dp[i-1]+lis[i];
        else dp[i]=dp[i-1]-lis[i];
        ans=max(ans,dp[i]);
    }
    if(s[n-1]=='A') dp[n-1]=lis[n-1];
    else dp[n-1]=-lis[n-1];
    ans=max(ans,dp[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]=='A') dp[i]=dp[i+1]+lis[i];
        else dp[i]=dp[i+1]-lis[i];
        ans=max(ans,dp[i]);
    }
    //cout<<ans<<endl;
    cout<<ini+ans;
}