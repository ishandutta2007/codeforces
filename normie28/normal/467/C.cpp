// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
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

#define ll  int64_t 
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
 
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
#define MAX 5000
ll dp[MAX+10][MAX+10];
ll arr[MAX+10],cumi[MAX+10];
ll n,m,k;
/*********FUNCTIONS**************/
ll calc(ll pos,ll nisi)
{
    if(nisi==k or pos>=n) return 0;
    else if(dp[pos][nisi]!=-1) return dp[pos][nisi];
    ll ret=0;
    if(pos+m-1<n)
    {
        ret=max(ret+(cumi[pos+m-1]-cumi[pos-1])+calc(pos+m,nisi+1),ret+calc(pos+1,nisi));
    }
    return dp[pos][nisi]=ret;
}
/***********MAIN**************/
 
signed main(){
    memset(dp,-1,sizeof dp);
    memset(arr,0,sizeof arr);
    memset(cumi,0,sizeof cumi);
    scanf("%lld %lld %lld",&n,&m,&k);
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    cumi[0]=arr[0];
    for(ll i=1;i<n;i++)
    {
        cumi[i]=cumi[i-1]+arr[i];
    }
    ll ans=calc(0,0);
    cout<<ans<<endl;
    return 0;
}
 
//