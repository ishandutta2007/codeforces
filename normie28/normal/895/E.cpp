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
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "sample.inp"
#define FILE_OUT "sample.out"
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
//---------END-------//
typedef long double int_t; // Element type
int_t star[1000001];
struct SegTree
{
    int_t lazya[4000004],val[4000004],lazyb[4000004]; //Contains the current value of each node, as well as the lazy propagation amount stored.
    int tree_n;
    void resetK (int node, int l, int r) // Resets the tree nodes. 
    {
        if (l==r) 
        {
            lazya[node]=1;
            lazyb[node]=0;
            val[node]=star[l];
        }
        else
        {
            int mid=(l+r)/2;
            resetK(node<<1,l,mid);
            resetK((node<<1)+1,mid+1,r);
            lazya[node]=1;
            lazyb[node]=0;
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
    }
    void reset(int n)
    {
        resetK(1,1,n);
        tree_n=n;
    }
    void flusha(int node, int l, int r)
    {
        lazya[node<<1]=lazya[(node<<1)]*lazya[node];
        lazyb[node<<1]=lazyb[(node<<1)]*lazya[node]+lazyb[node];
        
        lazya[(node<<1)+1]=lazya[(node<<1)+1]*lazya[node];
        lazyb[(node<<1)+1]=lazyb[(node<<1)+1]*lazya[node]+lazyb[node];
        
		int mid=(l+r)/2;
        val[(node<<1)]=val[(node<<1)]*lazya[node]+lazyb[node]*(mid-l+1);
        val[(node<<1)+1]=val[(node<<1)+1]*lazya[node]+lazyb[node]*(r-(mid+1)+1);
        lazya[node]=1;
        lazyb[node]=0;
    }
    void updateK(int node, int l, int r, int tar_l, int tar_r, int_t diffa, int_t diffb)
    {
    //    cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<' '<<diffa<<' '<<diffb<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            lazya[node]=lazya[node]*diffa;
            lazyb[node]=lazyb[node]*diffa+diffb;
            val[node]=diffa*val[node]+diffb*(r-l+1);
        }
        else
        {
            flusha(node,l,r);
            int mid=(l+r)/2;
            updateK(node<<1,l,mid,tar_l,tar_r,diffa,diffb);
            updateK((node<<1)+1,mid+1,r,tar_l,tar_r,diffa,diffb);
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
        
    }
    void update(int l, int r, int_t diffa, int_t diffb)
    {
        updateK(1,1,tree_n,l,r,diffa,diffb);
    }
    int_t getK(int node, int l, int r, int tar_l, int tar_r)
    {
 
    //    cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return 0;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            return val[node];
        }
        else
        {
            flusha(node,l,r);
            int mid=(l+r)/2;
            int_t aa; aa=getK(node<<1,l,mid,tar_l,tar_r);
            int_t bb; bb=getK((node<<1)+1,mid+1,r,tar_l,tar_r);
            return aa+bb;
        }
        
    }
    int_t get(int l, int r)
    {
        return getK(1,1,tree_n,l,r);
    }
};
SegTree st;
ll n,m,i,j,k,t,u,v,a,b;
ll l1,l2,r1,r2;
int main()
{
//	ofile;
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>star[i];
	st.reset(n);
	for (i=1;i<=m;i++)
	{
		cin>>t;
		if (t==1)
		{
			cin>>l1>>r1>>l2>>r2;
			ld a1=st.get(l1,r1);
			ld a2=st.get(l2,r2);
	//		cout<<a1<<' '<<a2<<endl;
			st.update(l1,r1,ld(r1-l1)/(r1-l1+1),a2/(r2-l2+1)/(r1-l1+1));
			st.update(l2,r2,ld(r2-l2)/(r2-l2+1),a1/(r1-l1+1)/(r2-l2+1));
		}
		else
		{
			cin>>l1>>r1;
			cout<<fixed<<setprecision(9)<<st.get(l1,r1)<<endl;
		}
	}
}