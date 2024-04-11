
// Problem : E. Binary Matrix
// Contest : Codeforces - Educational Codeforces Round 31
// URL : https://codeforces.com/contest/884/problem/E
// Memory Limit : 16 MB
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
struct dsu
{
	int n,par[40100],h[40100],sz[40100];
	dsu (int n)
	{
		for (int i=0;i<n;i++)
		{
			par[i]=-1;
			h[i]=0;
		}
		this->n=n;
	}
	
	void reset (int n)
	{
		for (int i=0;i<n;i++)
		{
			par[i]=-1;
			h[i]=0;
		}
		this->n=n;
	}
	int get_par(int x)
	{
		if (par[par[x]]==par[x]) return par[x];
		else return par[x]=get_par(par[x]);
	}
	int check_same(int a, int b)
	{
		return (get_par(a)==get_par(b));
	}
	int add_edge(int a, int b)
	{
		int ha=get_par(a),hb=get_par(b);
		if (ha!=hb)
		{
			if (h[ha]<h[hb])
			{
				par[ha]=hb;
			}
			else
			if (h[ha]>h[hb])
			{
				par[hb]=ha;
			}
			else
			{
				par[hb]=ha;
				h[ha]++;
			}
			return 1;
		}
		else return 0;
	}
};
int arr[40001][2],reg[40001][2];
int bruh[40001];
int n,m,i,j,k,t,t1,u,v,a,b;
int res;
int main()
{
	fio;
	cin>>n>>m;
	dsu gr(2*m);
	for (i=0;i<n;i++)
	{
		for (j=0;j<m/4;j++)
		{
			char c;
			cin>>c;
			u=c;
			if (u>=58) u-=7;
			u-=48;
			for (k=0;k<4;k++) arr[j*4+k][i%2]=(u>>(3-k))%2;
		}
		t=0;
		for (j=0;j<m;j++) if (arr[j][i%2])
		{
			while ((1)and(gr.par[t]!=-1)) {t++;assert((0<=t)and(t<2*m));}
			gr.par[t]=t;
			gr.h[t]=1;
			reg[j][i%2]=t;
			res++;
		}
		for (j=0;j+1<m;j++) if ((arr[j][i%2])and(arr[j+1][i%2]))
		res-=gr.add_edge(reg[j][i%2],reg[j+1][i%2]);
		for (j=0;j<m;j++) if ((arr[j][0])and(arr[j][1]))
		res-=gr.add_edge(reg[j][0],reg[j][1]);
		for (j=0;j<m;j++) if (arr[j][i%2]) reg[j][i%2]=gr.get_par(reg[j][i%2]);
		for (j=0;j<2*m;j++) bruh[j]=0;
		for (j=0;j<m;j++) bruh[reg[j][i%2]]=1;
		for (j=0;j<2*m;j++) if (!bruh[j])
		{
			gr.par[j]=-1;
			gr.h[j]=0;
		}
	}
	cout<<res;
}