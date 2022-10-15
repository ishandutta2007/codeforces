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
#define MOD (ll(1000000007))
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
    ll p,base;
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
vector<string> sts;
vector<vector<ll>> hsh;
ll pw2[2000001];
ll npw2[2000001];
ll pre[100001][26];
ll pwp[2000001];
string add,q;
ll hq[1000001];
ll n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	p=get_p();
	base=get_rand(27,p-1);
	sts.push_back("");
	cin>>n>>m;
	cin>>sts[0]>>add;
	pw2[0]=1;
	npw2[0]=1;
	pwp[0]=1;
	for (i=1;i<=2000000;i++)
	{
		pw2[i]=(pw2[i-1]*2)%MOD;
		pwp[i]=(pwp[i-1]*base)%p;
	}
	a=bow(2,MOD-2,MOD);
	for (i=1;i<=2000000;i++)
	{
		npw2[i]=(npw2[i-1]*a)%MOD;
	}
	for (i=1;i<=n;i++)
	{
		sts.push_back(sts[i-1]+add[i-1]+sts[i-1]);
		if (sts[i].size()>=1000000) break;
	}
	for (i=0;i<sts.size();i++)
	{
		hsh.push_back({0});
		for (char c: sts[i]) hsh[i].push_back((hsh[i][hsh[i].size()-1]*base+(c-96))%p);
	}
	for (i=1;i<=n;i++)
	{
		for (j=0;j<26;j++) pre[i][j]=pre[i-1][j];
		pre[i][add[i-1]-97]+=pw2[n-i];
		pre[i][add[i-1]-97]%=MOD;
	}
	for (t=0;t<m;t++)
	{
		cin>>u>>q;
		for (i=0;i<sts.size();i++) if (q.size()<=sts[i].size()) break;
		if (i>u) {
			cout<<0<<endl;
			continue;
		}
		for (j=1;j<=q.size();j++)
		{
			hq[j]=(hq[j-1]*base+(q[j-1]-96))%p;
		}
		b=0;
		for (j=0;j+q.size()<=sts[i].size();j++) 
		{
		if ((hsh[i][j+q.size()]-(hsh[i][j]*pwp[q.size()])%p+p)%p==hq[q.size()])
		{
			b+=pw2[u-i];
			b%=MOD;
		}
		}
		for (j=0;j<q.size();j++)
		
		if (
			((hsh[i][sts[i].size()]-(hsh[i][sts[i].size()-j]*pwp[j])%p+p)%p==hq[j])
		   and
		   	(hsh[i][q.size()-j-1]==(hq[q.size()]-(hq[j+1]*pwp[q.size()-1-j])%p+p)%p)
		   )
		{
	//	    cout<<"my ass\n";
			b+=(pre[u][q[j]-97]-pre[i][q[j]-97]+MOD)%MOD*npw2[n-u]%MOD;
			b%=MOD;
		}
		cout<<b<<endl;
	}
}