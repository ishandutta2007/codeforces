#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.4
	Changes:
    Added include-guards to help with writing in multiple source files.
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

/*
	Normie's implementation of suffix array.
	This implementation will actually sort the cyclic shifts, so you should to put a marker that's lower than
	any character (e.g. '$') at the end of the string.
	Right now it's gonna be basic, with only sorting of the suffixes.
*/
struct suff
{
	string s; // The string we will be using
	int n; // Its length
	int ord[400011]; // The ordering of each suffix/cyclic shift in the current sorted list (pairwise distinct)
	int rank[400011]; // The eqivalency rank of each suffix/cyclic shift in the current sorted list
	int rank2[400011]; // A temporary storage for rank.
	vector<int> buc[400011]; // Buckets for use during algorithm. 
	int fin[400011]; // The current sorted suffix/cyclis shift array (suffixes are represented by starting index)
	int lcp[400011]; // The lcp array: Longest common prefix between 2 sufixes/cyclic shifts.
	void build(string ss)
	{
		// Initializing stuff. 
		s=ss;
		n=s.length();
		for (int i=0;i<n;i++) 
		{
			ord[i]=i;
			rank[i]=0;
		}
		// Sorts the cyclic segments with increasing length until the cyclic segments become cyclic shifts. 
		for (int lv=0;(1<<lv)<=2*n;lv++) // Current iteration. The lv-th iteration sorts cyclic segments of size (2^lv).
		{
			if (lv==0) // For the first iteration, we simply use radix sort.
			{
				for (int i=0;i<n;i++)
				{
					buc[s[i]].push_back(i);
				}
				int u=0,v=0;
				for (int i=0;i<128;i++)
				{
					u=v;
					for (int g : buc[i])
					{
						ord[g]=v;
						rank[g]=u;
						fin[ord[g]]=g;
						v++;
					}
					buc[i].clear();
				}
			}
			else // For the following iterations, we represent each segment of size 2^lv 
			     // based on the rank of it's two subsegments of size 2^(lv-1).
			     // (First by rank[ [a...a+2^(lv-1)) ], then by rank[ [a+2^(lv-1)...a+2^lv) ]).
			{
				for (int i=0;i<n;i++) 
				// Here, we insert the segments [a..a+2^lv)
				// into the buckets in increasing order of rank[ [a+2^(lv-1)...a+2^lv) ].
				// But the segments are added into the buckets corresponding to rank[ [a...a+2^(lv-1)) ]. 
				// So when we iterate through the buckets and then the elements in each bucket, we should get the correct ordering
				// of segments of length (2^lv).
				{
					buc[rank[(fin[i]+n-(1<<(lv-1)))%n]].push_back((fin[i]+n-(1<<(lv-1)))%n);
				}
				int u=0;
				int v=0;
				// Alright, now we can update the arrays with new the new ordering and ranks.
				for (int i=0;i<n;i++)
				{
					u=v;
					for (int j=0;j<buc[i].size();j++)
					{
						if ((j)and(rank[(buc[i][j]+n+(1<<(lv-1)))%n]!=rank[(buc[i][j-1]+n+(1<<(lv-1)))%n]))
						{
							u=v;
						}
						ord[buc[i][j]]=v;
						rank2[buc[i][j]]=u;
						fin[v]=buc[i][j];
						v++;
					}
					buc[i].clear();
				}
				for (int i=0;i<n;i++) rank[i]=rank2[i];
			}
		//	cout<<"debugging at level "<<lv<<endl;
		//	cout<<"ord: "; for (int i=0;i<n;i++) cout<<ord[i]<<' '; cout<<endl;
		//	cout<<"rank: "; for (int i=0;i<n;i++) cout<<rank[i]<<' '; cout<<endl;
		//	cout<<"fin: "; for (int i=0;i<n;i++) cout<<fin[i]<<' '; cout<<endl;
		}
		// And that's it! I guess.
	}
	void buildlcp() // Builds the lcp array.
	{
		int k=0; // Current lower bound for lcp of next suffix.
		for (int i=0;i<n;i++) // Iterate through suffixes from long to short.
		{
			int u=ord[i];
			if (u==n-1) lcp[u]=0,k=0; // If the current suffix is last in array, lcp is by default, 0.
			else
			{ 
			while(s[(i+k)%n]==s[(fin[u+1]+k)%n]) k++; // Increases k while possible.
			lcp[u]=k; 
			k=max(k-1,0); // Moves on to next suffix.
			}
		}
	}
};
suff lmao;

struct dsu
{
	ll n,par[1000100],h[1000100],sz[1000100];
	dsu (ll n)
	{
		for (ll i=0;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
			h[i]=1;
		}
		this->n=n;
	}
	
	void reset (ll n)
	{
		for (ll i=0;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
			h[i]=1;
		}
		this->n=n;
	}
	ll get_par(ll x)
	{
		if (par[par[x]]==par[x]) return par[x];
		else return par[x]=get_par(par[x]);
	}
	ll check_same(ll a, ll b)
	{
		return (get_par(a)==get_par(b));
	}
	ll add_edge(ll a, ll b)
	{
		ll ha=get_par(a),hb=get_par(b);
		if (ha!=hb)
		{
			if (h[ha]<h[hb])
			{
				par[ha]=hb;
				sz[hb]+=sz[ha];
			}
			else
			if (h[ha]>h[hb])
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
			}
			else
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
				h[ha]++;
			}
			return 1;
		}
		else return 0;
	}
};
dsu gr(200001);

vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
string s,mk;
ll maxx=0,max2=0;
vector<pii(int)> merg[200001];
int main()
{
	fio;
    cin>>n;
    cin>>s>>mk;
    reverse(s.begin(),s.end());
    reverse(mk.begin(),mk.end());
    s.push_back(122);
    lmao.build(s);
    lmao.buildlcp();
    gr.reset(n);
    for (i=0;i<n;i++) if (mk[i]=='1') {gr.sz[i]=0;}
  //  for (i=0;i<=n;i++) cout<<"fin "<<i<<" = "<<lmao.fin[i]<<endl;
    for (i=0;i+1<n;i++) merg[lmao.lcp[i]].emplace_back(lmao.fin[i],lmao.fin[i+1]);
    //for (i=0;i<n;i++) cout<<gr.sz[i]; cout<<endl;
    for (i=n;i>=1;i--)
    {
        max2=max(max2,gr.sz[n-i]);
        for (auto g : merg[i])
        {
    //        cout<<i<<' '<<"merg"<<' '<<g.fi<<' '<<g.se<<endl;
            gr.add_edge(g.fi,g.se);
            max2=max(max2,gr.sz[gr.get_par(g.fi)]);
        }
        maxx=max(maxx,max2*i);
    //    cout<<i<<' '<<max2<<' '<<max2*i<<endl;
    }
    cout<<maxx<<endl;
}