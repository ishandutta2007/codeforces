/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
typedef long long int_t;
//---------END-------//
int_t star[500001];
struct SegTree
{
    int_t lazy[4000004],val[4000004],swa[21];
    int_t tree_n,tree_dep;
    void resetK (int_t node, int_t l, int_t r, int_t cd)
    {
        if (l==r) 
        {
            lazy[node]=0;
            val[node]=star[l];
        }
        else
        {
            int_t mid=(l+r)/2;
            resetK((node<<1)+0^swa[cd],l,mid,cd-1);
            resetK((node<<1)+1^swa[cd],mid+1,r,cd-1);
            lazy[node]=0;
            val[node]=val[(node<<1)+0^swa[cd]]+val[(node<<1)+1^swa[cd]];
        }
    }
    void reset(int_t n, int_t dep)
    {
        tree_n=n;
        tree_dep=dep;
        for (int i=0;i<tree_dep;i++) swa[i]=0;
        resetK(1,1,n,tree_dep-1);
    }
	void rev(int_t k)
	{
		for (int i=0;i<k;i++) swa[i]^=1;
	}
	void sw(int_t k)
	{
		swa[k]^=1;
	}
    void flusha(int_t node, int_t l, int_t r, int_t cd)
    {
        lazy[(node<<1)+0^swa[cd]]+=lazy[node];
        lazy[(node<<1)+1^swa[cd]]+=lazy[node];
        int_t mid=(l+r)/2;
        val[(node<<1)+0^swa[cd]]+=lazy[node]*(mid-l+1);
        val[(node<<1)+1^swa[cd]]+=lazy[node]*(r-(mid+1)+1);
        lazy[node]=0;
    }
    void updateK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t diff, int_t cd)
    {
    //    cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            lazy[node]+=diff;
            val[node]+=diff*(r-l+1);
        }
        else
        {
            flusha(node,l,r,cd);
            int_t mid=(l+r)/2;
            updateK((node<<1)+0^swa[cd],l,mid,tar_l,tar_r,diff,cd-1);
            updateK((node<<1)+1^swa[cd],mid+1,r,tar_l,tar_r,diff,cd-1);
            val[node]=val[(node<<1)+0^swa[cd]]+val[(node<<1)+1^swa[cd]];
        }
        
    }
    void update(int_t l, int_t r, int_t diff)
    {
        updateK(1,1,tree_n,l,r,diff,tree_dep-1);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t cd)
    {
 
   //     cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return 0;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            return val[node];
        }
        else
        {
            flusha(node,l,r,cd);
            int_t mid=(l+r)/2;
            int_t aa; aa=getK((node<<1)+0^swa[cd],l,mid,tar_l,tar_r,cd-1);
            int_t bb; bb=getK((node<<1)+1^swa[cd],mid+1,r,tar_l,tar_r,cd-1);
            return aa+bb;
        }
        
    }
    int_t get(int_t l, int_t r)
    {
        return getK(1,1,tree_n,l,r,tree_dep-1);
    }
};
SegTree st;
ll n,m,i,j,k,t,u,v,a,b;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=(1<<n);i++) cin>>star[i];
	st.reset(1<<n,n);
	for (i=1;i<=m;i++)
	{
		cin>>t;
		if (t==1)
		{
			cin>>a>>b;
			u=st.get(a,a);
			st.update(a,a,b-u);
		}
		else if (t==2)
		{
			cin>>a;
			st.rev(a);
		}
		else if (t==3)
		{
			cin>>a;
			st.sw(a);
		}
		else
		{
			cin>>a>>b;
			cout<<st.get(a,b)<<endl;
		}
	}
}