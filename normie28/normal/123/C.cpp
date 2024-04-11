
// Problem : C. Brackets
// Contest : Codeforces - Codeforces Beta Round #92 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/123/C
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
#define maxn 205
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
int n,m,val[maxn],id[maxn]; 
ll k,dp[maxn][maxn];
char res[maxn];
bool cmp(int a,int b)
{
    return val[a]<val[b];
}
int main()
{
	fio;
	cin>>n>>m>>k;
        int N=n+m-1;
        for(int i=1;i<=N;i++)val[i]=n*m,id[i]=i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int t;
                cin>>t;
                val[i+j-1]=min(val[i+j-1],t);
            }
        sort(id+1,id+N+1,cmp);
        memset(res,0,sizeof(res));
        for(int l=1;l<=N;l++)
        {
            res[id[l]]='(';
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            for(int i=0;i<N;i++)
                for(int j=i&1;j<=i&&j<=N-i;j+=2)
                    if(dp[i][j])
                    {
                        if(dp[i][j]>k)dp[i][j]=k;
                        if(res[i+1]!='('&&j)dp[i+1][j-1]+=dp[i][j];
                        if(res[i+1]!=')')dp[i+1][j+1]+=dp[i][j];
                    }
            if(k>dp[N][0])
            {
                k-=dp[N][0];
                res[id[l]]=')';
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cout<<res[i+j-1];
            cout<<endl;
        }
}