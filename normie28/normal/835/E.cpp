
// Problem : E. The penguin's game
// Contest : Codeforces - Codeforces Round #427 (Div. 2)
// URL : https://codeforces.com/problemset/problem/835/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int ask(vector<int> v)
{
	if (v.size()==0) return 0;
	cout<<"? "<<v.size()<<' ';
	for (int g : v) cout<<g+1<<' ';
	cout<<endl;
	int res;
	cin>>res;
	if (res==-1) exit(0);
	return res;
}
void answer(int x, int y)
{
	if (x>y) swap(x,y);
	x++;
	y++;
	cout<<"! "<<x<<' '<<y<<endl;
	exit(0);
}
vector<int> cur;
int n,m,i,j,k,t,t1,u,v,a,b,mas,id1,id2;
int filter[10];
int ask_with_filter()
{
	cur.clear();
	for (int j=0;j<n;j++) 
	{
		int fail=0;
	for (int i=0;i<10;i++)
		if ((filter[i]>-1)and(((j&(1<<i))>>i)!=filter[i])) fail=1;
		if (!fail) cur.push_back(j);
	}
	int a=ask(cur);
	return a;
}
int main()
{
	fio;
	cin>>n;
	cin>>a>>b;
	for (i=0;i<10;i++)
	{
		cur.clear();
		for (j=0;j<n;j++) if (j&(1<<i)) cur.push_back(j);
		u=ask(cur);
//		cout<<i<<' '<<u<<endl;
		if (u==((a*(cur.size()%2))^a^b)) 
		mas^=(1<<i);
		
	}
//	cout<<"mas="<<mas<<endl;
	for (i=0;i<10;i++) filter[i]=-1;
	for (i=0;i<10;i++) if (mas&(1<<i)) break;
	filter[i]=0;
	for (j=0;j<10;j++) if (filter[j]==-1)
	{
		filter[j]=0;
		u=ask_with_filter();
		if (u==((a*(cur.size()%2))^a^b)) ; else filter[j]=1;

	}
	for (j=0;j<10;j++) id1^=(1<<j)*filter[j];
	id2=id1^mas;
	answer(id1,id2);
}