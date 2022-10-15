/*
khoi orz, go check out his algo
-normie-
Tested with library-checker.
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
#define FILE_IN "birds.inp"
#define FILE_OUT "birds.out"
#define prev prv
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
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define ll long long
#define pi 3.1415926535897
//------START-----------//
typedef long long int_t;
int_t star[1000001];
struct SegTree
{
    int_t lazy[4000004],val[4000004];
    int_t tree_n;
    void resetK (int_t node, int_t l, int_t r)
    {
        if (l==r) 
        {
            lazy[node]=0;
            val[node]=star[l];
        }
        else
        {
            int_t mid=(l+r)/2;
            resetK(node<<1,l,mid);
            resetK((node<<1)+1,mid+1,r);
            lazy[node]=0;
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
    }
    void reset(int_t n)
    {
        resetK(1,1,n);
        tree_n=n;
    }
    void flusha(int_t node, int_t l, int_t r)
    {
        lazy[node<<1]+=lazy[node];
        lazy[(node<<1)+1]+=lazy[node];
        int_t mid=(l+r)/2;
        val[node<<1]+=lazy[node]*(mid-l+1);
        val[(node<<1)+1]+=lazy[node]*(r-(mid+1)+1);
        lazy[node]=0;
    }
    void updateK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t diff)
    {
   //     cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            lazy[node]+=diff;
            val[node]+=diff*(r-l+1);
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            updateK(node<<1,l,mid,tar_l,tar_r,diff);
            updateK((node<<1)+1,mid+1,r,tar_l,tar_r,diff);
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
        
    }
    void update(int_t l, int_t r, int_t diff)
    {
        updateK(1,1,tree_n,l,r,diff);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r)
    {
 
  //      cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return 0;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            return val[node];
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            int_t aa; aa=getK(node<<1,l,mid,tar_l,tar_r);
            int_t bb; bb=getK((node<<1)+1,mid+1,r,tar_l,tar_r);
            return aa+bb;
        }
        
    }
    int_t get(int_t l, int_t r)
    {
        return getK(1,1,tree_n,l,r);
    }
};

//---//
ll n,m,i,j,k,u,v,a,b,ress=0;
vector<pll> adds[100001],cur;
vector<ll> qs[100001];
ll l[100001],r[100001],res[100001];
map<pll,ll> latest;
SegTree st;
//------END-----------//
int main()
{
//    ofile;
    fio;
    cin>>n; st.reset(n);
    for (j=1;j<=n;j++) 
    {
        cur.clear();
        cin>>m;
        for (i=0;i<m;i++) 
        {
            cin>>u>>v;
            cur.push_back({u,v});
        }
        for (i=0;i<m;i++)
        {
            ll du=cur[(i+1)%m].fi-cur[i].fi;
            ll dv=cur[(i+1)%m].se-cur[i].se;
            if (du==0) adds[j].push_back({0,dv/abs(dv)});
            else if (dv==0) adds[j].push_back({du/abs(du),0});
            else 
            {
                ll gc=__gcd(abs(du),abs(dv));
                adds[j].push_back({du/gc,dv/gc});
            }
        }
    }
    cin>>m;
    for (i=1;i<=m;i++) 
    {
        cin>>l[i]>>r[i];
        qs[r[i]].push_back(i);
    }
    for (i=1;i<=n;i++)
    {
   //     cout<<"processing adds for "<<i<<endl;
        for (pll pp: adds[i])
        {
      //      cout<<"update "<<pp.fi<<' '<<pp.se<<' '<<latest[pp]<<endl;
            st.update(latest[pp]+1,i,1);
            latest[pp]=i;
        }
     //   cout<<"processing queries for "<<i<<endl;
        for (ll g : qs[i])
        {
            res[g]=st.get(l[g],l[g]);
        }
    }
    for (i=1;i<=m;i++) cout<<res[i]<<endl;
}