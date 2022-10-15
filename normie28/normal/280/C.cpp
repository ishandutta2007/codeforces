
//------------NMFF0B0H--------//
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "evadingin.txt"
#define FILE_OUT "evadingout.txt"
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
//-----------RND------------//
ll n,num,m,i,j,k,depth[100001],a,b;
deque<int> bruh;
vector<int> gt[100001];
double res;
string s,t;
int main()
{
    fio;
    cin>>n;
    for (i=1;i<n;i++)
    {
        cin>>a>>b;
        gt[a].push_back(b);
        gt[b].push_back(a);
    }
    bruh.push_back(1);
    depth[1]=1;
    while(bruh.size())
    {
        a=bruh.front();
        for (i=0;i<gt[a].size();i++)
        if (depth[gt[a][i]]==0)
        {
            depth[gt[a][i]]=depth[a]+1;
            bruh.push_back(gt[a][i]);
        }
        bruh.pop_front();
    }
    for (i=1;i<=n;i++) res+=double(1)/depth[i];
    cout<<fixed<<setprecision(10)<<res;
}