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
#define ll long long
#define pi 3.1415926535897
//------START-----------//
typedef unsigned int int_t;
int_t star[1000001];
int_t nodes=0;
struct node
{
    int_t lazy=0,val=0;
    node *nl=0, *nr=0;
};
struct DynamicSegTree
{
    node start;
    int_t nodecnt=1;
    DynamicSegTree()
    {
        nodes++;
    }
    void reset()
    {
        resetK(&start);
    }
    void resetK(node* cur)
    {
        cur->lazy=0;
        cur->val=0;
        if (cur->nl) resetK(cur->nl);
        if (cur->nr) resetK(cur->nr);
    }
    int_t get_nodecount()
    {
        return nodecnt;
    }
    void flusha(node* cur, int_t l, int_t r)
    {
        if (!(cur->nl)) {cur->nl=new(node); nodes++;}
        if (!(cur->nr)) {cur->nr=new(node); nodes++;}
        cur->nl->lazy+=cur->lazy;
        cur->nr->lazy+=cur->lazy;
        int_t mid=(l+r)/2;
        cur->nl->val+=(cur->lazy)*(mid-l+1);
        cur->nr->val+=(cur->lazy)*(r-(mid+1)+1);
        cur->lazy=0;
    }
    void updateK(node* cur, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t diff)
    {
   //     cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            cur->lazy+=diff;
            cur->val+=diff*(r-l+1);
        }
        else
        {
            flusha(cur,l,r);
            int_t mid=(l+r)/2;
            updateK(cur->nl,l,mid,tar_l,tar_r,diff);
            updateK(cur->nr,mid+1,r,tar_l,tar_r,diff);
            cur->val=(cur->nl->val)+(cur->nr->val);
        }
        
    }
    void update(int_t l, int_t r, int_t diff)
    {
        updateK(&start,0,2e9,l,r,diff);
    }
    int_t getK(node* cur, int_t l, int_t r, int_t tar_l, int_t tar_r)
    {
 
  //      cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return 0;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            return cur->val;
        }
        else
        {
            if (cur->nl)
            {
            flusha(cur,l,r);
            int_t mid=(l+r)/2;
            int_t aa; aa=getK(cur->nl,l,mid,tar_l,tar_r);
            int_t bb; bb=getK(cur->nr,mid+1,r,tar_l,tar_r);
            return aa+bb;
            }
            else
            {
                int_t truel=max(l,tar_l);
                int_t truer=min(r,tar_r);
                return (cur->val)/(r-l+1)*(truer-truel+1);
            }
        }
        
    }
    int_t get(int_t l, int_t r)
    {
        return getK(&start,0,2e9,l,r);
    }
};
map<int,DynamicSegTree> mp;
int n,m,i,j,k,t,u,v,a,b;
int x,r,q;
ll res=0;
vector<piii> lis;
//------END-----------//
int main()
{
//    ofile;
    fio;
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>x>>r>>q;
        lis.push_back({r,{x,q}});
    }
    sort(lis.begin(),lis.end(),[](piii a, piii b){return (a.fi>b.fi);});
    for (i=0;i<n;i++)
    {
        r=lis[i].fi;
        x=lis[i].se.fi;
        q=lis[i].se.se;
        for (j=q-k;j<=q+k;j++) if (mp.find(j)!=mp.end())
        {
            ll ql=max(x-r,0);
            ll qr=min(x+r,1e9);
            res+=mp[j].get(ql+5e8,qr+5e8);
        }
        mp[q].update(x+5e8,x+5e8,1);
   //     cout<<nodes<<endl;
    }
  //  if (n==10000) cout<<nodes<<endl;
    cout<<res;
}