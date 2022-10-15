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
struct cmp
{
	int operator()(piii(int) a, piii(int) b) const
	{
		return (a.se.se<b.se.se);
	}
};
set<piii(int),cmp> se;
string s,f,res;
int n,m,i,j,k,t,t1,u,v,a,b,fail;
int ql[200001],qr[200001];
vector<piii(int)> toadd;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>m;
		cin>>s>>f;
		for (i=1;i<=m;i++)
		{
			cin>>ql[i]>>qr[i];
		}
		j=1;
		se.clear();
		for (i=1;i<=n;i++)
		if ((i>1)and(f[i-1]!=f[i-2]))
		{
			se.insert({(f[i-2]-48),{j,i-1}});
			j=i;
		}
			se.insert({(f[i-2]-48),{j,i-1}});
			j=i;
			fail=0;
		//	for (auto g : se) cout<<g.fi<<' '<<g.se.fi<<' '<<g.se.se<<endl;
		for (i=m;i>=1;i--)
		{
			toadd.clear();
			auto it=se.lower_bound({0,{ql[i],ql[i]}});
			a=0;
			while(true)
			{
				
			//	cout<<"traversing "<<it->fi<<' '<<it->se.fi<<' '<<it->se.se<<endl;
				if (it->fi) a+=min(qr[i],it->se.se)-max(ql[i],it->se.fi)+1;
				if (ql[i]>it->se.fi)
				{
					toadd.push_back({it->fi,{it->se.fi,ql[i]-1}});
				}
				if (qr[i]<it->se.se)
				{
					toadd.push_back({it->fi,{qr[i]+1,it->se.se}});
				}
				if (qr[i]<=it->se.se) 
				{
					se.erase(it);
					break;
				}
				it=se.erase(it);
			}
			b=qr[i]-ql[i]+1;
		//	cout<<a<<' '<<b<<endl;
			if (a*2==b)
			{
				fail=1;
				break;
			}
			for (auto g : toadd) se.insert(g);
			if (a*2<b) se.insert({0,{ql[i],qr[i]}});
			else se.insert({1,{ql[i],qr[i]}});
		//	for (auto g : se) cout<<g.fi<<' '<<g.se.fi<<' '<<g.se.se<<endl;
		}
		if (fail)
		{
			cout<<"No\n";
			continue;
		}
		res.clear();
		for (auto g : se) for (i=g.se.fi;i<=g.se.se;i++) res.push_back(char(g.fi+48));
		if (res==s) cout<<"Yes\n";
		else cout<<"No\n";
	}
}