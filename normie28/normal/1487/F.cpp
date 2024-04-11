
// Problem : F. Ones
// Contest : Codeforces - Educational Codeforces Round 104 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1487/problem/F
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
void reduce(vector<int> &v)
{
	while ((v.size())and(v[v.size()-1]==0)) v.pop_back();
}
void string_to_vector(string &s, vector<int> &res)
{
	res.clear();
	for (int i=s.size()-1;i>=0;i--) res.push_back(s[i]-48);
	reduce(res);
}
void equalize(vector<int> &a, vector<int> &b)
{
	while(a.size()<b.size()) a.push_back(0);
	while(a.size()>b.size()) b.push_back(0);
}
void add(vector<int> &a, vector<int> &b, vector<int> &c)
{
	equalize(a,b);
	c.clear();
	int cur=0;
	for (int i=0;i<a.size();i++)
	{
		cur+=a[i];
		cur+=b[i];
		c.push_back(cur%10);
		cur/=10;
	}
	if (cur) c.push_back(cur);
	reduce(a);
	reduce(b);
	reduce(c);
}
int subtract(vector<int> &a, vector<int> &b, vector<int> &c)
{
	equalize(a,b);
	c.clear();
	int cur=0,sign=0;
	for (int i=a.size()-1;i>=0;i--) 
	if ((sign==0)and(a[i]>b[i])) sign=1; else if ((sign==0)and(a[i]<b[i])) sign=-1;
	if (sign>=0)
	{
		for (int i=0;i<a.size();i++)
		{
			cur+=a[i];
			cur-=b[i];
			c.push_back((cur+10)%10);
			if (cur<0) cur=-1; else cur=0;
		}
	}
	else
	{
		for (int i=0;i<a.size();i++)
		{
			cur+=b[i];
			cur-=a[i];
			c.push_back((cur+10)%10);
			if (cur<0) cur=-1; else cur=0;
		}
	}
	reduce(a);
	reduce(b);
	reduce(c);
	return sign;
}
void vector_to_string(vector<int> &v, string &res)
{
	res="";
	reduce(v);
		char c;
	for (int i=v.size()-1;i>=0;i--) 
	{
		c=v[i]+48;
		res.push_back(c);
	}
	if (res=="") res="0";
}
void addstr(string &a, string &b, string &c)
{
	vector<int> va,vb,vc;
	string_to_vector(a,va);
	string_to_vector(b,vb);
	add(va,vb,vc);
	vector_to_string(vc,c);
}
int subtractstr(string &a, string &b, string &c)
{
	vector<int> va,vb,vc;
	string_to_vector(a,va);
	string_to_vector(b,vb);
	int u=subtract(va,vb,vc);
	vector_to_string(vc,c);
	return u;
}
string stor[52];
string tar,sa,sb,sc;
map<string,int> dis;
struct cmp
{
	operator()(pair<string,int> a, pair<string,int> b)
	{
		return (a.se>b.se);
	}
};
priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	for (i=1;i<=51;i++) for (j=1;j<=i;j++) stor[i].push_back('1');
	cin>>tar;
	dis[tar]=0;
	pq.push({tar,0});
	while(true)
	{
		auto pp=pq.top(); pq.pop();
	//	cout<<pp.fi<<' '<<pp.se<<endl;
		if (dis[pp.fi]-pp.se) continue;
		if (pp.fi==string("0"))
		{
			cout<<pp.se;
			return 0;
		}
		for (i=max(pp.fi.size(),1);i<=min(pp.fi.size()+1,51);i++)
		{
			u=subtractstr(pp.fi,stor[i],sc);
			if (((dis.find(sc)==dis.end())or(dis[sc]>pp.se+i)))
			{
				dis[sc]=pp.se+i;
				pq.push({sc,pp.se+i});
			}
		}
	}
}