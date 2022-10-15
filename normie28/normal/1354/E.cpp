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
const int N = 5e3 + 113;
vector<int> edges[N];
int clr[N];
vector<int> v1, v2;
void dfs(int v)
{
    if(clr[v] == 2)
        v2.push_back(v);
    else
        v1.push_back(v);
    for(auto i : edges[v])
    {
 
        if(clr[i] == clr[v])
        {
            cout<<"NO"<<endl;
            exit(0);
        }
        if(!clr[i])
            clr[i] = (clr[v] % 2) + 1, dfs(i);
    }
}
bool dp[N][N];
pair<int, bool> anc[N][N];
bool chosen[N];
signed main()
{
	fio;
    int n, m;
    cin>>n>>m;
    int c1, c2, c3;
    cin>>c1>>c2>>c3;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<pair<vector<int>, vector<int>>> sum;
    for(int i = 1; i <= n; i++)
    {
        if(!clr[i])
            clr[i] = 1, dfs(i), sum.push_back({v1, v2}), v1.clear(), v2.clear();
    }
    dp[0][0] = 1;
    int c = 1;
    for(auto i : sum)
    {
        for(int j = N - 1; j >= 0; j--)
        {
            if(j >= i.first.size() && !dp[c][j] && dp[c - 1][j - i.first.size()])
                dp[c][j] = 1, anc[c][j] = {c - 1, 0};
            if(j >= i.second.size() && !dp[c][j] && dp[c - 1][j - i.second.size()])
                dp[c][j] = 1, anc[c][j] = {c - 1, 1};
        }
        c++;
    }
    if(!dp[sum.size()][c2])
    {
        cout<<"NO"<<endl;
        exit(0);
    }
    cout<<"YES"<<endl;
    vector<int> ans;
    int v = c2, sz1 = sum.size();
    while(v)
    {
        if(anc[sz1][v].second)
        {
            for(auto i : sum[anc[sz1][v].first].second)
                ans.push_back(i);
            v -= sum[anc[sz1][v].first].second.size();
            sz1--;
        }
        else
        {
            for(auto i : sum[anc[sz1][v].first].first)
                ans.push_back(i);
            v -= sum[anc[sz1][v].first].first.size();
            sz1--;
        }
    }
    for(auto i : ans)
        chosen[i] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(chosen[i])
            cout<<2;
        else
        {
            if(c1)
                cout<<1, c1--;
            else
                cout<<3;
        }
    }
    cout<<endl;
}