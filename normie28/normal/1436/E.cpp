/*
    New, shiny, hand-crafted segtree template.
    Perfect for use in any online contest.
    Tested with Codeforces Edu and library-checker. 
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
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
typedef int int_t;
int_t star[1000001];
struct SegTree
{
    int_t lazy[4000004],val[4000004];
    int_t tree_n;
    void resetK (int_t node, int_t l, int_t r)
    {
        if (l==r) 
        {
            val[node]=l;
        }
        else
        {
            int_t mid=(l+r)/2;
            resetK(node<<1,l,mid);
            resetK((node<<1)+1,mid+1,r);
            val[node]=min(val[node<<1],val[(node<<1)+1]);
        }
    }
    void reset(int_t n)
    {
        resetK(1,0,n);
        tree_n=n;
    }
    void updateK(int_t node, int_t l, int_t r, int_t tar, int_t diff)
    {
   //     cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar)or(r<tar)) return;
        else if (l==r)
        {
            val[node]=min(val[node],diff);
        }
        else
        {
            int_t mid=(l+r)/2;
            updateK(node<<1,l,mid,tar,diff);
            updateK((node<<1)+1,mid+1,r,tar,diff);
            val[node]=min(val[node<<1],val[(node<<1)+1]);
        }
        
    }
    void update(int_t x, int_t diff)
    {
        updateK(1,0,tree_n,x,diff);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r)
    {
 
  //      cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return 1e9;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            return val[node];
        }
        else
        {
            int_t mid=(l+r)/2;
            int_t aa; aa=getK(node<<1,l,mid,tar_l,tar_r);
            int_t bb; bb=getK((node<<1)+1,mid+1,r,tar_l,tar_r);
            return min(aa,bb);
        }
        
    }
    int_t get(int_t l, int_t r)
    {
        return getK(1,0,tree_n,l,r);
    }
};
SegTree st;
int n,m,i,j,k,t,u,v,a,b;
int arr[200011];
vector<int> buc[200011];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    st.reset(n);
    for (i=1;i<=n+5;i++) buc[i].push_back(0);
    for (i=1;i<=n;i++)
    {
        cin>>arr[i];
        buc[arr[i]].push_back(i);
    }
    for (i=1;i<=n+5;i++) buc[i].push_back(n+1);
    i=1;
    while(true)
    {
        ll done=0;
        for (j=1;j<buc[i].size();j++)
        {
            if (st.get(buc[i][j]-1,n)>buc[i][j-1]) done=1;
            st.update(buc[i][j]-1,buc[i][j-1]);
        }
        if (!done) break;
        else i++;
    }
    cout<<i;
}