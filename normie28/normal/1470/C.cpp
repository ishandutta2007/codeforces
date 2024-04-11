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
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)

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


    seed_seq seq{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
    };
    mt19937 rng(seq);
int get_rand(int l, int r)
{
        return uniform_int_distribution<int>(l,r)(rng);
}


int arr[100001];
int brr[100001];
int remain[100001];
int n,m,i,j,k,t,t1,u,v,a,b,cnt,q,dis,flagg;
int ask(int x)
{
	q++;
	assert(q<=1000);
	cout<<"? "<<x+1<<endl;
	int a;
	cin>>a;
	return a;
}
int answer(int x)
{
	cout<<"! "<<x+1<<endl;
	exit(0);
}
int main()
{
	fio;
	cin>>n>>k;
	dis=sqrt(n);
	for (i=0;i<n;i++) 
	{
		arr[i]=k;
		remain[i]=1;
	}
	cnt=n;
	while(true)
	{
		u=get_rand(0,n-1);
		v=ask(u);
		if (v!=k) break;
	}
	if(v>k)
	{
		while(true)
		{
			u+=n-1; u%=n;
			v=ask(u);
			if (v==k) answer(u);
		}
	}
	else
	{
		while(true)
		{
			u+=1; u%=n;
			v=ask(u);
			if (v==k) answer(u);
		}
	}
}