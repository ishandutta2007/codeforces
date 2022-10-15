
// Problem : E. Magical Permutation
// Contest : Codeforces - Codeforces Round #558 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1163/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
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
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
PL seg[1510];
LL N,S,M,K;
LL dp[1510][1510];
LL A[1510],P[1510];
inline bool chk(LL X)
{
    LL i,j,k;
    LL cnt=0;
    for(i=0;i<=N;i++)
        fill(dp[i],dp[i]+M+1,0);
    for(i=1;i<=N;i++)
        P[i]=P[i-1]+(A[i]>X?0:1);
    for(i=j=0;i<N;i++)
    {
        while(j<S)
        {
            if(seg[j].first==i+1)
            {
                cnt=max(cnt,seg[j].second-i);
                j++;
            }
            else
                break;
        }
        for(k=0;k<M;k++)
        {
            dp[i+1][k]=max(dp[i+1][k],dp[i][k]);
            if(i+cnt<=N)
                dp[i+cnt][k+1]=max(dp[i+cnt][k+1],dp[i][k]+P[i+cnt]-P[i]);
        }
        dp[i+1][M]=max(dp[i+1][M],dp[i][M]);
        if(cnt>0)
            cnt--;
    }
    return dp[N][M]>=K;
}
LL i;
LL s,e,mid;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>S>>M>>K;
    for(i=1;i<=N;i++)
        cin>>A[i];
    for(i=0;i<S;i++)
        cin>>seg[i].first>>seg[i].second;
    sort(seg,seg+S);
    s=0;
    e=INF;
    if(!chk(e))
        return cout<<-1<<endl,0;
    while(s<e)
    {
        mid=s+e>>1;
        if(chk(mid))
            e=mid;
        else
            s=mid+1;
    }
    cout<<s<<endl;
}