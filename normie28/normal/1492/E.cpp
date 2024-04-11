 
// Problem : E. Almost Fault-Tolerant Database
// Contest : Codeforces - Codeforces Round #704 (Div. 2)
// URL : https://codeforces.com/contest/1492/problem/E
// Memory Limit : 512 MB
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
vector<vector<int>> board;
int n,m,i,j,k,t,t1,u,v,a,b;
void win()
{
	cout<<"Yes\n";
	for (i=0;i<m;i++) cout<<board[0][i]<<' ';
	exit(0);
}
void tri(int cnt)
{
	vector<int> vec; int i,j,k,u,v;
	for (i=1;i<n;i++)
	{
		vec.clear();
		for (j=0;j<m;j++) if (board[0][j]-board[i][j]) vec.push_back(j);
		if (vec.size()>2) break;
	}
	if (i==n) win();
	else
	{
		if (vec.size()>=5) return;
		else if (vec.size()==3) 
		{
			if (cnt+1>2) return;
			for (j=0;j<3;j++)
			{
				u=board[0][vec[j]];
				board[0][vec[j]]=board[i][vec[j]];
				tri(cnt+1);
				board[0][vec[j]]=u;
			}
		}
		else  
		{
			if (cnt+2>2) return;
			for (j=0;j<4;j++) for (k=j+1;k<4;k++)
			{
				u=board[0][vec[j]];
				v=board[0][vec[k]];
				board[0][vec[j]]=board[i][vec[j]];
				board[0][vec[k]]=board[i][vec[k]];
				tri(cnt+2);
				board[0][vec[j]]=u;
				board[0][vec[k]]=v;
			}
		}
	}
}
int main()
{
    fio;
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		board.push_back({});
		for (j=0;j<m;j++)
		{
			cin>>u;
			board[i].push_back(u);
		}
	}
	tri(0);
	cout<<"No";
}