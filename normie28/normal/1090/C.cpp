/*
    New, shiny, hand-crafted segtree template.
    Perfect for use in any online contest.
    Tested with Codeforces Edu.
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
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n,m,i,j,k,t;
int a,b,u,v,l,r,cnts,cntt,mid;
ordered_set buc[100001];
struct cmp
{
    int operator()(int a, int b)
    {
        if (buc[a].size()==buc[b].size()) return (a<b);
        return (buc[a].size()<buc[b].size());
    }
};
set<int,cmp> bruh;
vector<piii> moves;
int main()
{
    fio;
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>k;
        for (j=1;j<=k;j++)
        {
            cin>>u;
            buc[i].insert(u);
        }
        bruh.insert(i);
    }
  //  for (int g : bruh) cout<<g<<' '; cout<<endl;
    while(true)
    {
        auto it=bruh.end();
        it--;
        int source=(*(it));
        int tar=(*(bruh.begin()));
      //  cout<<source<<' '<<tar<<endl;
        if (buc[source].size()-buc[tar].size()<=1) break;
        l=1;r=m;
        while(l<r)
        {
            mid=(l+r)/2;
            cnts=buc[source].order_of_key(mid+1)-buc[source].order_of_key(l);
            cntt=buc[tar].order_of_key(mid+1)-buc[tar].order_of_key(l);
            if (cnts>cntt) r=mid; else l=mid+1;
        }
        bruh.erase(source);
        bruh.erase(tar);
        buc[source].erase(l);
        buc[tar].insert(l);
        moves.push_back({source,{tar,l}});
        bruh.insert(source);
        bruh.insert(tar);
    }
    cout<<moves.size()<<endl;
    for (piii gg : moves) cout<<gg.p1<<' '<<gg.p2<<' '<<gg.p3<<endl;
}