// Problem: F. Permutation
// Contest: Codeforces - MemSQL Start[c]UP 2.0 - Round 1
// URL: https://codeforces.com/problemset/problem/452/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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
 
 
 
    seed_seq seq{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
    };
    mt19937 rng(seq);
    int prime(ll x)
    {
    	if (x<2) return 0;
    	for (int i=2;i<=sqrt(x);i++) if (x%i==0) return 0;
    	return 1;
    }
ll get_rand(ll l, ll r)
{
	return uniform_int_distribution<ll>(l,r)(rng);
}
ll get_p()
{
	ll res;
	while(true)
	{
		res=get_rand(1e9,2e9);
		if (prime(res)) return res;
	}
}
ll bow (ll a, ll x, ll p)
{
	if (!x) return 1;
    ll res=bow(a,x/2,p);
    res*=res;
    res%=p;
    if (x%2) res*=a;
    res%=p;
    return res;
}
 
ll state[300001];
ll ptb[300001];
ll invtb[300001];
#define hash hashhh
SegTree hash,hashrev;
vector<ll> vec;
ll n,m,i,j,k,t,t1,u,v,a,b,p,ba;
ll arr[300001];
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++) cin>>arr[i];
	p=get_p();
	ba=get_rand(5,p-1);
	ptb[0]=1;
	for (i=1;i<=n;i++)
	{
		ptb[i]=(ptb[i-1]*ba)%p;
	}
	a=bow(ba,p-2,p);
	invtb[0]=1;
	for (i=1;i<=n;i++)
	{
		invtb[i]=(invtb[i-1]*a)%p;
	}
	hash.reset(n);
	hashrev.reset(n);
	for (i=1;i<=n;i++)
	{
		if ((arr[i]>1)and(arr[i]<n))
		{
			j=arr[i];
			a=min(j-1,n-j);
			u=hash.get(j-a,j-1);
			v=hashrev.get((n+1)-(j+a),(n+1)-(j+1));
			u%=p;
			v%=p;
			u=(u*invtb[j-a])%p;
			v=(v*invtb[(n+1)-(j+a)])%p;
	//		cout<<i<<' '<<u<<' '<<v<<endl;
			if (u-v)
			{
				cout<<"YES";
				return 0;
			}
		}
		hash.update(arr[i],arr[i],ptb[arr[i]]);
		hashrev.update(n+1-arr[i],n+1-arr[i],ptb[n+1-arr[i]]);
	}
	cout<<"NO";
}