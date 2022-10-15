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
            val[node]=-1e9;
        }
        else
        {
            int_t mid=(l+r)/2;
            resetK(node<<1,l,mid);
            resetK((node<<1)+1,mid+1,r);
            lazy[node]=0;
            val[node]=max(val[node<<1],val[(node<<1)+1]);
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
        	val[node]=diff;
        }
        else
        {
            int_t mid=(l+r)/2;
            updateK(node<<1,l,mid,tar_l,tar_r,diff);
            updateK((node<<1)+1,mid+1,r,tar_l,tar_r,diff);
            val[node]=max(val[node<<1],val[(node<<1)+1]);
        }
        
    }
    void update(int_t l, int_t r, int_t diff)
    {
        updateK(1,1,tree_n,l,r,diff);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r)
    {
 
  //      cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return -1e9;
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
            return max(aa,bb);
        }
        
    }
    int_t get(int_t l, int_t r)
    {
        return getK(1,1,tree_n,l,r);
    }
};
ll n,m,i,j,k,t,flag,res=-1e9;
ll a,b,u,v;
ll arr[1000001],mk[1000001],lis[1000001],dp[1000001],ord[1000001];
vector<ll> seeds;
SegTree st;
int main()
{
    fio;
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
    	cin>>arr[i];
    	seeds.push_back(i);
    }
    arr[0]=-1e9;
    seeds.push_back(0);
    sort(seeds.begin(),seeds.end(),[](int a, int b){return (arr[a]-a<arr[b]-b);});
    for (i=0;i<=n;i++) ord[seeds[i]]=i+1;
    st.reset(n+1);
    for (i=1;i<=m;i++)
    {
    	cin>>lis[i];
    	mk[lis[i]]=i;
    }
    j=0;
    dp[0]=0;
    st.update(ord[0],ord[0],dp[0]);
    for (i=1;i<=n;i++)
    {
    	if (mk[i-1])
    	{
    		for (k=j;k<i-1;k++) st.update(ord[k],ord[k],-1e9);
    		j=i-1;
    	}
    	int tar=(upper_bound(seeds.begin(),seeds.end(),i,[](int a, int b){return (arr[a]-a<arr[b]-b);})-seeds.begin());
    	dp[i]=1+st.get(1,tar);
    	st.update(ord[i],ord[i],dp[i]);
    	if (mk[i]==m) flag=1;
    	if (flag)  res=max(res,dp[i]);
    }
	if (res<0) cout<<-1; else cout<<n-res;
}