#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "exp.inp"
#define FILE_OUT "exp.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(111539768))
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
typedef long long ll;
//-------------HASH----------//
//-------------END-----------//
int n,m,i,j,k,t,t1,p,rcnt[100001],res[100001],used[100001],maxx=-100,istree,aad,bad;
vector<pii> e;
vector<pii> gt[100001];
vector<int> v,v2;
ll cnt=0;
void dfs(int x)
{
    used[x]=1;
    if ((x!=i)and(rcnt[x]==1))
    {
        if (v.size()==n-1)
        {
        for (int i=0;i<n-1;i++) cout<<i<<endl; exit(0);}
        else
        {
            int j;
            res[v[0]]=0;
            res[v[v.size()-1]]=1;
            for (j=1;j<v.size()-1;j++) res[v[j]]=j+2;
            j+=2;
            if (j==n-1) j=2;
            for (int i=0;i<n-1;i++) if (res[i]<0) {res[i]=j; j++; if (j==n-1) j=2;}
            for (int i=0;i<n-1;i++) cout<<res[i]<<endl;
            exit(0);
        }
    }
    for (int i=0;i<gt[x].size();i++)
    {
        pii a=gt[x][i];
        if (!used[a.fi])
        {
            v.push_back(a.se);
            dfs(a.fi);
            v.pop_back();
        }
    }
}
int main(){
    fio;
    cin>>n;
    for (i=0;i<n-1;i++)
    {
        res[i]=-1;
        cin>>aad>>bad;
        e.push_back(pii({aad,bad}));
        gt[aad].push_back({bad,i});
        gt[bad].push_back({aad,i});
        rcnt[aad]++;
        rcnt[bad]++;
    }
    for (i=1;i<=n;i++) if (rcnt[i]==1) break;
    dfs(i);
}