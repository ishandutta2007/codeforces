// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
#define int long long
#define inf 100000000000000000 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
#define mod 1000000007
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/

set<int>s,notf[300005];
int mp[300005];
 
/*********FUNCTIONS**************/

/***********MAIN**************/

signed main(){ 
      int n,i,j;
    cin>>n;
    ll c[n+1];
    for(i=1;i<=n;++i)
        cin>>c[i];
    string s[n+1];
    for(i=1;i<=n;++i)
        cin>>s[i];
 
    ll dp[n+1][2];
    for(i=0;i<=n;++i)
        dp[i][0]=dp[i][1]=inf;
    dp[1][0]=0;
    dp[1][1]=c[1];
 
    string s2,s3;
    for(i=2;i<=n;++i)
    {
        s2=s[i-1];
        reverse(s2.begin(),s2.end());
        s3=s[i];
        reverse(s3.begin(),s3.end());
 
        if(s[i]>=s[i-1])
            dp[i][0]=dp[i-1][0];
 
        if(s[i]>=s2)
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
 
        if(s3>=s[i-1] and dp[i-1][0]!=inf)
            dp[i][1]=dp[i-1][0]+c[i];
 
        if(s3>=s2 and dp[i-1][1]!=inf)
            dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
    }
    ll ans=min(dp[n][1],dp[n][0]);
    if(ans==inf)
    cout<<"-1"<<endl;
    else
    cout<<ans<<endl;
}