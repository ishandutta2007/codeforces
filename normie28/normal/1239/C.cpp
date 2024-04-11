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
struct event
{
	char typ=0;
	ll t=0;
	ll n=0;
	event(char _typ=0, ll _t=0, ll _n=0)
	{
		typ=_typ;
		t=_t;
		n=_n;
	}
	bool operator<(const event oth) const
	{
		if (t-oth.t) return (t>oth.t);
		else if (typ-oth.typ) return (typ>oth.typ);
		else return (n>oth.n);
	}
	event& operator=(const event& oth)
	{
		typ=oth.typ;
		t=oth.t;
		n=oth.n;
		return (*this);
	}
	
};
priority_queue<event> pq;
set<ll> inq,waiting;
deque<ll> dq;
ll n,m,i,j,k,u,v,a,b;
ll t[100001],res[100001];
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>t[i];
		pq.push({'a',t[i],i});
	}
	while(pq.size())
	{
		event cur=pq.top();
	//	cout<<cur.typ<<' '<<cur.t<<' '<<cur.n<<endl;
		pq.pop();
		if (cur.typ=='a')
		{
			waiting.insert(cur.n);
		}
		else
		{
			dq.pop_front();
			res[cur.n]=cur.t;
			inq.erase(cur.n);
			if (dq.size())
			{
				pq.push({'b',cur.t+m,dq.front()});
			}
		}
		if (waiting.size())
		{
			u=(*(waiting.begin()));
			if (inq.lower_bound(u)==inq.begin())
			{
				dq.push_back(u);
				waiting.erase(u);
				inq.insert(u);
				if (dq.size()==1)
				pq.push({'b',cur.t+m,u});
			}
		}
	}
	for (i=1;i<=n;i++) cout<<res[i]<<' ';
}