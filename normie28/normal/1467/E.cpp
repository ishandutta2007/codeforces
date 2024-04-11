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
	int val[1000001],cnt[1000001],lazy[1000001];
	void reset(int l, int r, int cur)
	{
		val[cur]=0;
		lazy[cur]=0;
		cnt[cur]=r-l+1;
		if (l<r)
		{
			ll mid=(l+r)/2;
			reset(l,mid,(cur<<1));
			reset(mid+1,r,(cur<<1)+1);
		}
	}
	void flusha(int cur)
	{
		val[(cur<<1)]+=lazy[cur];
		val[(cur<<1)+1]+=lazy[cur];
		lazy[(cur<<1)]+=lazy[cur];
		lazy[(cur<<1)+1]+=lazy[cur];
		lazy[cur]=0;
	}
	void update(int l, int r, int cur, int tl, int tr, int d)
	{
	//	cout<<"update "<<tl<<' '<<tr<<endl;
		if (tl>tr) return;
		if ((tl>r)or(tr<l)) return;
		if ((tl<=l)and(tr>=r))
		{
			val[cur]+=d;
			lazy[cur]+=d;
		}
		else
		{
			flusha(cur);
			ll mid=(l+r)/2;
			update(l,mid,(cur<<1),tl,tr,d);
			update(mid+1,r,(cur<<1)+1,tl,tr,d);
			if (val[(cur<<1)]<val[(cur<<1)+1])
			{
				val[cur]=(val[(cur<<1)+1]);
				cnt[cur]=cnt[(cur<<1)+1];
			}
			else if (val[(cur<<1)]>val[(cur<<1)+1])
			{
				val[cur]=(val[(cur<<1)]);
				cnt[cur]=cnt[(cur<<1)];
			}
			else
			{
				val[cur]=(val[(cur<<1)]);
				cnt[cur]=cnt[(cur<<1)]+cnt[(cur<<1)+1];
			}
		}
	}
};
seg st;
vector<int> buc[200001];
int tl[200001], tr[200001];
int col[200001];
map<int,int> mp;
vector<int> gt[200001];
vector<int> down[200001];
int n,m,i,j,k,t,t1,u,v,a,b,colcnt;
void dfs(int x)
{
	t++;
	tl[x]=t;
	for (int g : gt[x]) if (!tl[g]) {dfs(g); down[x].push_back(g);}
	tr[x]=t;
}
int get_range(int c, int l, int r)
{
	if (l>r) return 0;
	return lower_bound(buc[c].begin(),buc[c].end(),r+1)-lower_bound(buc[c].begin(),buc[c].end(),l);
}
int main()
{
	fio;
	cin>>n;
	st.reset(1,n,1);
	for (i=1;i<=n;i++)
	{
		cin>>col[i];
		if (mp[col[i]]==0)
		{
			colcnt++;
			mp[col[i]]=colcnt;
		}
		col[i]=mp[col[i]];
	}
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	
	dfs(1);
	for (i=1;i<=n;i++)
	{
		buc[col[i]].push_back(tl[i]);
	}
	for (i=1;i<=n;i++) sort(buc[i].begin(),buc[i].end());
	for (i=1;i<=n;i++)
	{
		for (int g : down[i])
		{
			if (get_range(col[i],tl[g],tr[g])<buc[col[i]].size()-1) st.update(1,n,1,tl[g],tr[g],-1);
		}
		if (get_range(col[i],1,tl[i]-1)+get_range(col[i],tr[i]+1,n)<buc[col[i]].size()-1)
		{
			st.update(1,n,1,1,tl[i]-1,-1);
			st.update(1,n,1,tr[i]+1,n,-1);
		}
		if (buc[col[i]].size()>=2) st.update(1,n,1,tl[i],tl[i],-1);
	}
	if (st.val[1]<0) cout<<0;
	else cout<<st.cnt[1];
}