#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
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

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
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

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#endif

typedef long long int_t; // Element type
int_t star[1000001];
struct SegTree
{
    int_t lazy[4000004],val[4000004]; //Contains the current value of each node, as well as the lazy propagation amount stored.
    int_t tree_n;
    void resetK (int_t node, int_t l, int_t r) // Resets the tree nodes.
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
        if (l>r) return;
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
        if (l>r) return 0;
        return getK(1,1,tree_n,l,r);
    }
};
SegTree st;






// vector<[int]> vec;
int n,m,q,i,j,k,t,t1,u,v,a,b;
int arr[300001];
int enc[300001];
int mn[300001][20];
vector<int> buc[300001];
vector<piii(int)> sta[300001];
vector<int> qs[300001];
ll ql[300001],qr[300001],qx[300001];

int getMin(int l, int r) {
	int u=floor(log2(r-l+1));
	return min(mn[l][u],mn[r-(1<<u)+1][u]);
}

int main()
{
	fio;
	cin>>n>>q>>m;
	for (i=0;i<n;i++) cin>>arr[i];
	for (i=0;i<q;i++) {
		cin>>ql[i]>>qr[i];
		ql[i]--;
		qr[i]--;
		qs[ql[i]].push_back(i);
	}
	for (i=0;i<n;i++) {
		buc[i%m].push_back(i);
	}
	t=-1;
	for (i=0;i<m;i++) {
		for (auto g : buc[i]) {
			t++;
			enc[g]=t;
		}
	}
	for (j=0;j<=19;j++) 
	for (i=0;i<n;i++) {
		if (j==0) mn[i][j]=arr[i];
		else {
			mn[i][j]=mn[i][j-1];
			if (i+(1<<(j-1))<n) mn[i][j]=min(mn[i][j],mn[i+(1<<(j-1))][j-1]);
		}

	}

	st.resetK(1,0,n-1);
	for (i=n-1;i>=0;i--) {
		if (sta[i%m].size()==0) {
			st.updateK(1,0,n-1,enc[i],enc[i],arr[i]);
			sta[i%m].push_back({arr[i],{i,i}});
		}
		else {
			v=i;
			a=getMin(i+1,i+m);
			while(sta[i%m].size() && sta[i%m].back().p1>=a) {
				st.updateK(1,0,n-1,enc[sta[i%m].back().p2],enc[sta[i%m].back().p3],-sta[i%m].back().p1);
				v=sta[i%m].back().p3;
				sta[i%m].pop_back();
			}
			if (v>i) {
				st.updateK(1,0,n-1,enc[i+m],enc[v],a);
				sta[i%m].push_back({a,{i+m,v}});
			}
			v=i;
			a=arr[i];
			while(sta[i%m].size() && sta[i%m].back().p1>=a) {
				st.updateK(1,0,n-1,enc[sta[i%m].back().p2],enc[sta[i%m].back().p3],-sta[i%m].back().p1);
				v=sta[i%m].back().p3;
				sta[i%m].pop_back();
			}
			st.updateK(1,0,n-1,enc[i],enc[v],a);
			sta[i%m].push_back({a,{i,v}});
		}
		for (auto g : qs[i]) {
			u=ql[g];
			v=qr[g];
			v=u+(v-u)/m*m;
			qx[g]=st.getK(1,0,n-1,enc[u],enc[v]);
		}
	}
	for (i=0;i<q;i++) {
		cout<<qx[i]<<endl;
	}
}