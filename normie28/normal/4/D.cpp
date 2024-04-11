// Credit to robs77 for this template
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
/***********MACROS***************/
#define int long long 
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
/*********VARIABLE****************/
using namespace std;
pair<int , pair< int , int > >q[9000];
int dp[9000];
int p[9000];
int anss[9000];
int indexx=0;
 
/*********FUNCTIONS**************/

 
/***********MAIN**************/

signed main(){
   int n,x,y;
    cin>>n>>x>>y;
    for(int i=0;i<n;i++)
    {
        cin>>q[i].first>>q[i].second.first;
        q[i].second.second=i;
    }
    sort(q,q+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(q[i].first<=x||q[i].second.first<=y)
            continue;
        dp[i]=1;
        for(int j=0;j<n;j++)
        {
            if(q[j].first>=q[i].first||q[j].second.first>=q[i].second.first||q[j].first<x||q[j].second.first<y)
                continue;
            if(dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                p[i]=j;
            }
        }
        if(dp[i]>ans)
            ans=dp[i],indexx=i;
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
    {
        anss[i]=q[indexx].second.second;
        indexx=p[indexx];
    }
    for(int i=ans-1;i>=0;i--)
        cout<<anss[i]+1<<" ";
    cout<<endl;
}

//