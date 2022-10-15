
// Problem : E. Triple Flips
// Contest : Codeforces - Technocup 2019 - Elimination Round 2
// URL : https://codeforces.com/problemset/problem/1031/E
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

const int maxn=1e5+10,mod=1e9+7,inf=0x3f3f3f3f;
int n,m,k,t,a[maxn];
int dp[1<<10],pd[3][1<<10];
int dp1[1<<6],pd1[3][1<<6];
void init(int n=10)
{
    queue<int>que;
    dp[0]=0;
    que.push(0);
    while(!que.empty())
    {
        int p=que.front();
        que.pop();
        for(int i=1;i+i<n;i++)
            for(int j=0;j+i+i<n;j++)
            {
                int q=p^(1<<j)^(1<<(j+i))^(1<<(j+i+i));
                if(!~dp[q])que.push(q),dp[q]=dp[p]+1,pd[0][q]=j,pd[1][q]=j+i,pd[2][q]=j+i+i;
            }
    }
}
void init1()
{
    queue<int>que;
    dp1[0]=0;
    que.push(0);
    while(!que.empty())
    {
        int p=que.front();
        que.pop();
        for(int i=1;i+i<=10;i++)
            for(int j=0;j+i+i<=10 && j<6;j++)
        {
            int q=p^(1<<j);
            if(j+i<6)q^=(1<<(j+i));
            if(j+i+i<6)q^=(1<<(j+i+i));
            if(!~dp1[q])que.push(q),dp1[q]=dp1[p]+1,pd1[0][q]=j,pd1[1][q]=j+i,pd1[2][q]=j+i+i;
        }
    }
}
int main()
{
    int i,j;
  	memset(dp,-1,sizeof(dp));
  	memset(dp1,-1,sizeof(dp1));
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(n<10)
    {
        init(n);
        int cur=0;
        for(i=n-1;i>=0;i--)
            cur=(cur<<1)+a[i];
        if(!~dp[cur])puts("NO");
        else
        {
            puts("YES");
            queue<int>ret;int cnt=0;
            while(cur)
            {
                cnt++;
                ret.push(pd[0][cur]+1);
                ret.push(pd[1][cur]+1);
                ret.push(pd[2][cur]+1);
                cur=cur^(1<<pd[0][cur])^(1<<pd[1][cur])^(1<<pd[2][cur]);
            }
            printf("%d\n",cnt);
            while(!ret.empty())
            {
                printf("%d",ret.front());ret.pop();
                printf(" %d ",ret.front());ret.pop();
                printf("%d\n",ret.front());ret.pop();
            }
        }
        return 0;
    }
    init1();
    queue<int>ret;int cnt=0;
    while(n>=11)
    {
        int cur=0;
        for(int i=n-6;i<n;i++)
            cur=(cur<<1)+a[i];
        while(cur)
        {
            cnt++;
            ret.push(n-pd1[0][cur]);
            a[n-1-pd1[0][cur]]^=1;
            ret.push(n-pd1[1][cur]);
            a[n-1-pd1[1][cur]]^=1;
            ret.push(n-pd1[2][cur]);
            a[n-1-pd1[2][cur]]^=1;
            int nxt=cur;
            if(pd1[0][cur]<6)nxt^=(1<<pd1[0][cur]);
            if(pd1[1][cur]<6)nxt^=(1<<pd1[1][cur]);
            if(pd1[2][cur]<6)nxt^=(1<<pd1[2][cur]);
            cur=nxt;
        }
        n-=6;
    }
    init();
    int cur=0;
    for(i=9;i>=0;i--)
        cur=(cur<<1)+a[i];
    while(cur)
    {
        cnt++;
        ret.push(pd[0][cur]+1);
        ret.push(pd[1][cur]+1);
        ret.push(pd[2][cur]+1);
        cur=cur^(1<<pd[0][cur])^(1<<pd[1][cur])^(1<<pd[2][cur]);
    }
    puts("YES");
    printf("%d\n",cnt);
    while(!ret.empty())
    {
        printf("%d",ret.front());ret.pop();
        printf(" %d ",ret.front());ret.pop();
        printf("%d\n",ret.front());ret.pop();
    }
}