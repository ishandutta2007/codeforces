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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define pi 3.1415926535897
//------START-----------//
ll bow (ll a, ll x)
{
    if (!x) return 1;
    ll res=bow(a,x/2);
    res*=res; res%=MOD;
    if (x%2) res*=a;
    return (res%MOD);
}
ll pwr[301][50001];
typedef long long int_t;
int_t star[1000001];
ll pwr_cnt(ll a, ll x)
{
	ll res=1;
	while(x>=50000)
	{
		res*=pwr[a][50000];
		res%=MOD;
		x-=50000;
	}
	res*=pwr[a][x];
	return res%MOD;
}
struct MulSegTree
{
    int_t lazy[1600004],val[1600004];
    int_t tree_n;
    void resetK (int_t node, int_t l, int_t r)
    {
        if (l==r) 
        {
            lazy[node]=1;
            val[node]=star[l];
        }
        else
        {
            int_t mid=(l+r)/2;
            resetK(node<<1,l,mid);
            resetK((node<<1)+1,mid+1,r);
            lazy[node]=1;
            val[node]=val[node<<1]*val[(node<<1)+1];
            val[node]%=MOD;
        }
    }
    void reset(int_t n)
    {
        resetK(1,1,n);
        tree_n=n;
    }
    void flusha(int_t node, int_t l, int_t r)
    {
        lazy[node<<1]*=lazy[node]; lazy[node<<1]%=MOD;
        lazy[(node<<1)+1]*=lazy[node]; lazy[(node<<1)+1]%=MOD;
        int_t mid=(l+r)/2;
        val[node<<1]*=bow(lazy[node],(mid-l+1));val[node<<1]%=MOD;
        val[(node<<1)+1]*=bow(lazy[node],(r-(mid+1)+1));val[(node<<1)+1]%=MOD;
        lazy[node]=1;
    }
    void updateK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t diff)
    {
   //     cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            lazy[node]*=diff;
            val[node]*=pwr_cnt(diff,(r-l+1));
            lazy[node]%=MOD;
            val[node]%=MOD;
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            updateK(node<<1,l,mid,tar_l,tar_r,diff);
            updateK((node<<1)+1,mid+1,r,tar_l,tar_r,diff);
            val[node]=val[node<<1]*val[(node<<1)+1];
            val[node]%=MOD;
        }
        
    }
    void update(int_t l, int_t r, int_t diff)
    {
        updateK(1,1,tree_n,l,r,diff);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r)
    {
 
  //      cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return 1;
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
            return (aa*bb)%MOD;
        }
        
    }
    int_t get(int_t l, int_t r)
    {
        return getK(1,1,tree_n,l,r);
    }
};
 

struct OrSegTree
{
    int_t lazy[1600004],val[1600004];
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
            val[node]=val[node<<1]|val[(node<<1)+1];
        }
    }
    void reset(int_t n)
    {
        resetK(1,1,n);
        tree_n=n;
    }
    void flusha(int_t node, int_t l, int_t r)
    {
        lazy[node<<1]|=lazy[node]; 
        lazy[(node<<1)+1]|=lazy[node]; 
        int_t mid=(l+r)/2;
        val[node<<1]|=lazy[node];
        val[(node<<1)+1]|=lazy[node];
        lazy[node]=0;
    }
    void updateK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t diff)
    {
   //     cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            lazy[node]|=diff;
            val[node]|=diff;
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            updateK(node<<1,l,mid,tar_l,tar_r,diff);
            updateK((node<<1)+1,mid+1,r,tar_l,tar_r,diff);
            val[node]=val[node<<1]|val[(node<<1)+1];
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
            return (aa|bb);
        }
        
    }
    int_t get(int_t l, int_t r)
    {
        return getK(1,1,tree_n,l,r);
    }
};
//---//
ll n,m,i,j,k,u,v,a,b,l,r,ress=0;
ll pr[301],inv[301],ind[301];
ordered_set remain[301];
MulSegTree st;
OrSegTree ost;
string s;
vector<ll> prlis;
//------END-----------//
int main()
{
//    ofile;
    fio;
    cin>>n>>m;
    for (i=1;i<=n;i++) cin>>star[i];
    for (i=1;i<=300;i++) pwr[i][0]=1;
    for (i=1;i<=50000;i++) for (j=1;j<=300;j++) pwr[j][i]=(pwr[j][i-1]*j)%MOD;
    st.reset(n);
    for (i=2;i<=300;i++) pr[i]=-1;
    pr[1]=1;
    for (i=2;i<=300;i++) if (pr[i]==-1)
    {
 //       for (j=1;j<=n;j++) remain[i].insert(j);
        inv[i]=bow(i,MOD-2);
        prlis.push_back(i); ind[i]=prlis.size()-1;
        for (j=i*i;j<=300;j+=i) pr[j]=i;
        pr[i]=i;
    }
    for (i=1;i<=n;i++)
    {
 //   	cout<<"factorizing arr["<<i<<"]:\n"
        v=star[i];
            ll staging=0;
            while(v>1)
            {
               staging|=((ll)1<<(ind[pr[v]]));
                v/=pr[v];
            }
            star[i]=staging;
    }
    ost.reset(n);
    for (u=1;u<=m;u++)
    {
        cin>>s;
        if (s=="MULTIPLY")
        {
            cin>>l>>r>>a;
            st.update(l,r,a);
            v=a;
            ll staging=0;
            while(v>1)
            {
               staging|=((ll)1<<(ind[pr[v]]));
                v/=pr[v];
            }
            ost.update(l,r,staging);
        }
        else
        {
            cin>>l>>r;
            ress=st.get(l,r);
   //         cout<<ress<<endl;
            v=ost.get(l,r);
     //       cout<<v<<endl;
            for (i=0;i<62;i++)
            {
                if (v%2)
                {
       //             cout<<prlis[i]<<endl;
                    ress*=(prlis[i]-1); ress%=MOD;
                    ress*=inv[prlis[i]]; ress%=MOD;
                }
                v/=2;
            }
  //          cout<<endl;
            cout<<ress<<endl;
   //         cout<<endl;
        }
    }
    
}