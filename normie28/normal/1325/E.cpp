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
int pr[1000001];
int dis[1000001];
vector<pii(int)> gt[1000001];
int adjcnt[1000001];
vector<int> plis;
int n,m,i,j,k,t,t1,u,v,a,b,res=1e9;
vector<int> br;
deque<pii(int)> dq;
int main()
{
	fio;
	for (i=2;i<=1000000;i++)
	for (j=i;j<=1000000;j+=i)
	if (!pr[j]) pr[j]=i;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>u;
		plis.clear();
		v=u;
		while(v>1)
		{
			plis.push_back(pr[v]);
			v/=pr[v];
		}
		sort(plis.begin(),plis.end());
		j=0;
		while(j+2<=plis.size())
		{
			if (plis[j]==plis[j+1])
			{
				plis.erase(plis.begin()+j);
				plis.erase(plis.begin()+j);
			}
			else
			j++;
		}
		if (plis.size()==0) 
		{
			cout<<1;
			return 0;
		}
		else if (plis.size()==1)
		{
			gt[plis[0]].push_back({1,t});
			gt[1].push_back({plis[0],t});
			t++;
		}
		else
		{
			gt[plis[0]].push_back({plis[1],t});
			gt[plis[1]].push_back({plis[0],t});
			t++;
		}
	}
	for (i=1;i<=1000000;i++) if (gt[i].size()) br.push_back(i);
	for (i=1;i<=1000;i++) if (gt[i].size())
	{
		for (int g : br) dis[g]=1e9;
		dis[i]=0;
		dq.push_back({i,-1});
		while(dq.size())
		{
			u=dq.front().fi;
			v=dq.front().se;
		//	cout<<"uv "<<u<<' '<<v<<endl;
			dq.pop_front();
			for (auto g : gt[u]) if (dis[g.fi]==1e9)
			{
		//		cout<<"next "<<u<<"->"<<g.fi<<endl;
				dis[g.fi]=dis[u]+1;
				dq.push_back({g.fi,g.se});
			}
			else if ((v!=g.se))
			{
				res=min(res,1+dis[u]+dis[g.fi]);
			}
		}
	}
	if (res==1e9) cout<< -1;
	else cout<< res;
}