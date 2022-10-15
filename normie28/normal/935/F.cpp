
// Problem : F. Fafa and Array
// Contest : Codeforces - Codeforces Round #465 (Div. 2)
// URL : https://codeforces.com/contest/935/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
struct seg
{
	ll val[500001];
	void reset(int c, int l, int r)
	{
		val[c]=0;
		if (l<r)
		{
			int mid=(l+r)/2;
			reset((c<<1),l,mid);
			reset((c<<1)+1,mid+1,r);
		}
	}
	void update(int c, int l, int r, int t, ll x)
	{
		if ((l<=t)and(t<=r))
		{
			if (l==r)
			{
				val[c]=x;
			}
			else
			{
				int mid=(l+r)/2;
				update((c<<1),l,mid,t,x);
				update((c<<1)+1,mid+1,r,t,x);
				val[c]=min(val[(c<<1)],val[(c<<1)+1]);
			}
		}
	}
	ll get(int c, int l, int r, int tl, int tr)
	{
		if ((l>tr)or(r<tl)) return 1e18;
		if ((l>=tl)and(r<=tr)) return val[c];
		else 
		{
			int mid=(l+r)/2;
			ll a=get((c<<1),l,mid,tl,tr);
			ll b=get((c<<1)+1,mid+1,r,tl,tr);
			return min(a,b);
		}
	}
};
seg st;
ll n,m,i,j,k,t,t1,u,v,a,b,l,r,inc;
ll dif[100001];
ll arr[100001];
ll typ[100001];
ll cur;
set<int> cl[3];
void uncalc(int x)
{
	cl[typ[x]].erase(x);
	st.update(1,1,n,x,1e18);
}
void calc(int x)
{
	if ((dif[x]>=0)and(dif[x+1]<=0)) 
	{
		typ[x]=0;
	}
	else if ((dif[x]<0)and(dif[x+1]>0))
	{
		typ[x]=1;
	}
	else
	{
		typ[x]=2;
		st.update(1,1,n,x,max(-dif[x],dif[x+1]));
	}
	cl[typ[x]].insert(x);
}
int main()
{
	fio;
	cin>>n;
	st.reset(1,1,n);
	for (i=1;i<=n;i++) cin>>arr[i];
	dif[1]=1e18;
	for (i=2;i<=n;i++) dif[i]=arr[i]-arr[i-1];
	dif[n+1]=-1e18;
	for (i=1;i<=n;i++)
	{
		uncalc(i);
		calc(i);
	}
	for (i=2;i<=n;i++) cur+=abs(dif[i]);
	cin>>m;
	for (t=1;t<=m;t++)
	{
		cin>>u>>l>>r>>inc;
	//	cout<<"c"<<' '<<cur<<endl;
		if (u==1)
		{
			auto it=cl[0].lower_bound(l);
			if ((it!=cl[0].end())and((*it)<=r))
			{
				cout<<cur+2*inc;
			}
			else
			{
				u=0;
				auto it2=cl[1].lower_bound(l);
				if ((it2!=cl[1].end())and((*it2)<=r))
				{
					v=(*it2);
					a=cur;
					if (v>1) 
					{
						a-=abs(dif[v]);
						a+=abs(dif[v]+inc);
					}
					if (v<n)
					{
						a-=abs(dif[v+1]);
						a+=abs(dif[v+1]-inc);
					}
					u=max(u,a);
				}
				a=st.get(1,1,n,l,r);
				if (a-1e18)
				{
				if (a>inc) b=cur;
				else b=2*(inc-a)+cur;
				
				u=max(u,b);
				}
				cout<<u;
			}
			cout<<endl;
		}
		else 
		{
			if (l>1)
			{
				uncalc(l-1);
				uncalc(l);
				cur-=abs(dif[l]);
				dif[l]+=inc;
				cur+=abs(dif[l]);
				calc(l-1);
				calc(l);
			}
			if (r<n)
			{
				uncalc(r);
				uncalc(r+1);
				cur-=abs(dif[r+1]);
				dif[r+1]-=inc;
				cur+=abs(dif[r+1]);
				calc(r);
				calc(r+1);
			}
		}
	}
}