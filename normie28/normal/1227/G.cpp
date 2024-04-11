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
    seed_seq seq{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
    };
    mt19937 rng(seq);
    int prime(ll x)
    {
    	if (x<2) return 0;
    	for (ll i=2;i<=sqrt(x);i++) if (x%i==0) return 0;
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
ll pr=0,n,m,i,j,k,t,t1,u,v,a,b;
vector<ll> lis;
ll num[5001];
string res[5001];
ll arr[5001];
int main()
{
//	ofile;
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for (i=1;i<=n+1;i++)
	{
		lis.push_back(i);
	}
	pr=get_p()*get_p();
	for (j=1;j<=n;j++)
	{
		b=arr[j];
		a=n+1-arr[j];
		sort(lis.begin(),lis.end(),[](ll a, ll b){
			return (num[a]<num[b]);
		});
		for (i=0;i<n;i++) if (num[lis[i]]==num[lis[i+1]])
		{
			a--;
			b--;
			res[lis[i]].push_back('0');
			res[lis[i+1]].push_back('1');
			num[lis[i]]*=2;
			num[lis[i+1]]*=2;
			num[lis[i+1]]++;
			num[lis[i]]%=MOD;
			num[lis[i+1]]%=MOD;
			break;
		}
		for (i=1;i<=n+1;i++) if (res[i].length()<j)
		{
			if (a>0)
			{
				num[i]*=2;
				num[i]%=MOD;
				res[i].push_back('0');
				a--;
			}
			else 
			{
				num[i]*=2;
				num[i]++;
				num[i]%=MOD;
				res[i].push_back('1');
				b--;
			}
		}
	}
	a=n+1;
	for (i=1;i<=n+1;i++) if (num[i]==0) a--;
	cout<<a<<endl;
	for (i=1;i<=n+1;i++) if (num[i]) cout<<res[i]<<endl;
}