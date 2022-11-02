#include<bits/stdc++.h>
#define MAXN 200007
using namespace std;
int n;
long long a[MAXN];
int dp[2][2][MAXN];
map<char,int> mp;
string s;
long long pok(char a,char b)
{
    dp[0][0][1]=dp[1][0][1]=dp[0][1][1]=dp[1][1][1]=1000000000;
    dp[mp[b]][(a==b)][1]=(a!=s[0])+(b!=s[1]);
    for(int i=2;i<n;i++)
    {
        int  lc=(s[i]!='L'),rc=(s[i]!='R');
        dp[0][0][i]=min(dp[1][0][i-1],dp[1][1][i-1])+rc;
        dp[1][0][i]=min(dp[0][0][i-1],dp[0][1][i-1])+lc;
        dp[0][1][i]=dp[0][0][i-1]+rc;
        dp[1][1][i]=dp[1][0][i-1]+lc;
    }
    if(a=='L' && b=='R') return min(dp[0][0][n-1],min(dp[0][1][n-1],dp[1][0][n-1]));
    if(a=='R' && b=='L') return min(dp[0][0][n-1],min(dp[1][1][n-1],dp[1][0][n-1]));
    if(a=='R' && b=='R') return min(dp[1][0][n-1],dp[1][1][n-1]);
    if(a=='L' && b=='L') return min(dp[0][0][n-1],dp[0][1][n-1]);
}
int main()
{
    mp['L']=1;
    mp['R']=0;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        long long sol=min(min(pok('L','L'),pok('R','R')),min(pok('R','L'),pok('L','R')));
        cout<<sol<<"\n";
    }
}