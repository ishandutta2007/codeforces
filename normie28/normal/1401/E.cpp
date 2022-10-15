
// Problem : E. Divide Square
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1401/E
// Memory Limit : 384 MB
// Time Limit : 2000 ms
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
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>

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
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;

//---------END-------//
ll n,m,i,j,u,t,k,v,arr[100001],res=0;
vector<piii(ll)> lis;
ordered_set hol,cur;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>k>>u>>v;
		if (u==0) lis.push_back({k,{1,v}});
		else lis.push_back({k,{3,u}});
	}
	for (i=1;i<=m;i++)
	{
		cin>>k>>u>>v;
		if (u==0) {if (v<1000000) lis.push_back({v,{0,k}});  cur.insert(k);}
		else lis.push_back({u,{2,k}});
	}
	sort(lis.begin(),lis.end(),[](piii(ll) a, piii(ll) b)
	{
		if (a.p1<b.p1) return true;
		else if (a.p1>b.p1) return false;
		else 
		{
			int val1,val2;
			if (a.p2==2) val1=0;
			else if ((a.p2==1)or(a.p2==3)) val1=1;
			else val1=2;
			if (b.p2==2) val2=0;
			else if ((b.p2==1)or(b.p2==3)) val2=1;
			else val2=2;
			return (val1<val2);
		}
	}
	);
	for (piii(ll) g : lis)
	{
	//	cout<<g.p1<<' '<<g.p2<<' '<<g.p3<<endl;
		if (g.p2==0) cur.erase(g.p3);
		else if (g.p2==2) hol.insert(g.p3);
		else
		{
	//		cout<<cur.size()<<endl;
	//		for (ll g : cur) cout<<g<<' '; cout<<endl;
			if (g.p2==1) 
			{
				
		//		cout<<"add "<<cur.order_of_key(g.p3+1)<<endl;
				res+=cur.order_of_key(g.p3+1);
				if (g.p3==1000000) res++;
				while(hol.size())
				{
					ll nxt=(*(hol.begin()));
		//			cout<<"nxt "<<nxt<<endl;
					if (nxt<=g.p3)
					{
						hol.erase(nxt);
						cur.insert(nxt);
					}
					else break;
				}
			}
			else
			{
		//		cout<<"add "<<cur.size()-cur.order_of_key(g.p3)<<endl;
				res+=cur.size()-cur.order_of_key(g.p3);
				if (g.p3==0) res++;
				while(hol.size())
				{
					ll nxt=(*(--hol.end()));
		//			cout<<"nxt "<<nxt<<endl;
					if (nxt>=g.p3)
					{
						hol.erase(nxt);
						cur.insert(nxt);
					}
					else break;
				}
			}
		//	cout<<res<<endl;
		}
	}
	cout<<res+cur.size()+1<<endl;
}