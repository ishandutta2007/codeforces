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
struct seg
{
	int val[800001],cnt[800001],lazy[800001];
	int n;
	void resetK(int l, int r, int cur)
	{
		val[cur]=0;
		cnt[cur]=r-l+1;
		lazy[cur]=0;
		if (l<r)
		{
			int mid=(l+r)/2;
			resetK(l,mid,(cur<<1));
			resetK(mid+1,r,(cur<<1)+1);
		}
	}
	void reset(int nn)
	{
		n=nn;
		resetK(1,n,1);
	}
	void flusha(int cur)
	{
	//	cout<<"flusha "<<cur<<endl;
	//	cout<<"before: "<<lazy[(cur<<1)]<<' '<<val[(cur<<1)]<<' '<<lazy[(cur<<1)+1]<<' '<<val[(cur<<1)+1]<<endl;
		lazy[(cur<<1)]+=lazy[cur];
		val[(cur<<1)]+=lazy[cur];
		lazy[(cur<<1)+1]+=lazy[cur];
		val[(cur<<1)+1]+=lazy[cur];
	//	cout<<"after: "<<lazy[(cur<<1)]<<' '<<val[(cur<<1)]<<' '<<lazy[(cur<<1)+1]<<' '<<val[(cur<<1)+1]<<endl;
		lazy[cur]=0;
	}
	void updateK(int l, int r, int cur, int tl, int tr, int d)
	{
		if ((tl>r)or(tr<l)) return;
		if ((tl<=l)and(tr>=r)) 
		{
	//		cout<<"update directly "<<cur<<' '<<d<<endl;
	//		cout<<"before: "<<val[cur]<<' '<<lazy[cur]<<endl;
			val[cur]+=d;
			lazy[cur]+=d;
	//		cout<<"after: "<<val[cur]<<' '<<lazy[cur]<<endl;
		}
		else
		{
			int mid=(l+r)/2;
			flusha(cur);
			updateK(l,mid,(cur<<1),tl,tr,d);
			updateK(mid+1,r,(cur<<1)+1,tl,tr,d);
			if (val[(cur<<1)]>val[(cur<<1)+1])
			{
				val[cur]=val[(cur<<1)];
				cnt[cur]=cnt[(cur<<1)];
			}
			else
			if (val[(cur<<1)]<val[(cur<<1)+1])
			{
				val[cur]=val[(cur<<1)+1];
				cnt[cur]=cnt[(cur<<1)+1];
			}
			else
			{
				val[cur]=val[(cur<<1)+1];
				cnt[cur]=cnt[(cur<<1)]+cnt[(cur<<1)+1];
			}
		}
	}
	void update(int l, int r, int d)
	{
		if (l>r) return;
		updateK(1,n,1,l,r,d);
	//	debug();
	}
	void debugK(int l, int r, int cur)
	{
		cout<<"---------------------------------\n";
		cout<<"Now crawling node: "<<cur<<endl;
		cout<<"Covering range: ("<<l<<","<<r<<")"<<endl;
		cout<<"It's values: "<<"val = "<<val[cur]<<" cnt = "<<cnt[cur]<<" lazy = "<<lazy[cur]<<endl;
		cout<<"---------------------------------\n";
		int mid=(l+r)/2;
		if (l<r)
		{
		debugK(l,mid,(cur<<1));
		debugK(mid+1,r,(cur<<1)+1);
		}
	}
	void debug()
	{
		debugK(1,n,1);
	}
};
seg st;
int n,m,i,j,k,t,u,v,a,b,targ;
map<int,int> mp[200001];
vector<int> gt[200001];
int l[200001],r[200001];
int par[200001][19];
void dfs(int x)
{
	k++;
	l[x]=k;
	for (int g : gt[x]) if (!l[g]) {
	dfs(g); par[g][0]=x;}
	r[x]=k;
}
void change_in(int x, int mul)
{
//	cout<<"change_in "<<x<<endl;
	st.update(l[x],r[x],mul);
}
void change_out(int x, int mul)
{
//	cout<<"change_out "<<x<<endl;
	st.update(1,l[x]-1,mul);
	st.update(r[x]+1,n,mul);
}
void change (int u, int v, int mul)
{
	int w;
	if ((l[u]>=l[v])and(l[u]<=r[v])) 
	{
		change_in(u,mul);
		w=u;
		for (int i=18;i>=0;i--) if ((l[par[w][i]]>l[v])and(l[par[w][i]]<=r[v])) w=par[w][i];
		change_out(w,mul);
	}
	else
	if ((l[v]>=l[u])and(l[v]<=r[u])) 
	{
		change_in(v,mul);
		w=v;
		for (int i=18;i>=0;i--) if ((l[par[w][i]]>l[u])and(l[par[w][i]]<=r[u])) w=par[w][i];
		change_out(w,mul);
	}
	else
	{
		change_in(u,mul);
		change_in(v,mul);
	}
	targ+=mul;
}
int main()
{
//	ofile;
	fio;
	cin>>n>>m;
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	dfs(1);
	par[1][0]=1;
	for (i=1;i<19;i++)
	{
		for (j=1;j<=n;j++) par[j][i]=par[par[j][i-1]][i-1];
	}
	st.reset(n);
	for (i=1;i<=n;i++)
	{
//		cout<<l[i]<<' '<<r[i]<<endl;
	}
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		if (u>v) swap(u,v);
//		cout<<u<<' '<<v<<endl;
		if (mp[u][v])
		{
			mp[u][v]=0;
			change(u,v,-1);
		}
		else
		{
			mp[u][v]=1;
			change(u,v,1);
		}
		if (st.val[1]==targ) cout<<st.cnt[1];
		else cout<<0;
		cout<<endl;
	}

}