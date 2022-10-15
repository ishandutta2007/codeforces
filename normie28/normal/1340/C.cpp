/*
 A Submission by NMFF0B0H
 at time: 2020-04-23 21:53:45
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],pos[100001],t,t1,i,j,dp[10000][1001],r,g,res;
vector<int> post;
struct cmp
{
int operator()(pair<ll,pair<int,int>> a, pair<ll,pair<int,int>> b)
{
    return (a.fi>b.fi);
}
};
priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,cmp> bruh;
void proc (pair<ll,pair<int,int>> cur)
{
    ll time=cur.p1,pos=cur.p2,gtime=cur.p3;
    if (time>dp[pos][gtime]) return;
    if (gtime==g)
    {
            if (dp[pos][gtime]+r<dp[pos][0]) bruh.push({dp[pos][gtime]+r,{pos,0}});
            dp[pos][0]=min(dp[pos][0],dp[pos][gtime]+r);
    }
    else
    {
        if ((pos>0)and(gtime+post[pos]-post[pos-1]<=g))
        {
            if (dp[pos][gtime]+post[pos]-post[pos-1]<dp[pos-1][gtime+post[pos]-post[pos-1]]) 
            bruh.push({dp[pos][gtime]+post[pos]-post[pos-1],{pos-1,gtime+post[pos]-post[pos-1]}});
            dp[pos-1][gtime+post[pos]-post[pos-1]]=
            min(dp[pos-1][gtime+post[pos]-post[pos-1]],dp[pos][gtime]+post[pos]-post[pos-1]);
            
        }
        if ((pos<m-1)and(gtime+post[pos+1]-post[pos]<=g))
        {
            if (dp[pos][gtime]+post[pos+1]-post[pos]<dp[pos+1][gtime+post[pos+1]-post[pos]])
            bruh.push({dp[pos][gtime]+post[pos+1]-post[pos],{pos+1,gtime+post[pos+1]-post[pos]}});
            dp[pos+1][gtime+post[pos+1]-post[pos]]=
            min(dp[pos+1][gtime+post[pos+1]-post[pos]],dp[pos][gtime]+post[pos+1]-post[pos]);
            
        }
    }
    
}
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    for (i=0;i<m;i++)
    {
        cin>>t;
        post.push_back(t);
    }
    cin>>g>>r;
    for (i=0;i<m;i++) for (j=0;j<=g;j++) dp[i][j]=1000000000000000000;
    
    sort(post.begin(),post.end());
    dp[0][0]=0;
    bruh.push({0,{0,0}});
    while(bruh.size())
    {
        pair<ll,pair<int,int>> toproc=bruh.top();
        bruh.pop();
        proc(toproc);
    }
    res=1e18;
    for (i=0;i<=g;i++) res=min(res,dp[m-1][i]);
    if (res==1e18) cout<<-1; else cout<<res;
    
}