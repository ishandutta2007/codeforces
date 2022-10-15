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
string s[3001],t[3001],key,str;
ll l[3001],r[3001];
ll lcp[7001];
ll n,m,i,j,k,t1,u,v,a,b;
vector<ll> co;
void check(ll cur)
{
	str=key+"#"+s[cur];
	lcp[0]=0;
	u=-1;
	for (ll i=1;i<str.size();i++)
	{
		j=lcp[i-1];
		while(true)
		{
			if (j==0)
			{
				if (str[i]==str[j]) 
				{
					lcp[i]=j+1;
					break;
				}
				else
				{
					lcp[i]=j;
					break;
				}
			}
			else
			{
				if (str[i]==str[j]) 
				{
					lcp[i]=j+1;
					break;
				}
				else
				{
					j=lcp[j-1];
				}
			}
		}
		if (lcp[i]==key.size())
		{
			u=i-key.size()-1;
			break;
		}
	}
	if (u-r[cur])
	{
		cout<<"NO";
		exit(0);
	}
}
int main()
{
	fio;
	cin>>n;
	for (i=0;i<n;i++) cin>>s[i];
	for (i=0;i<n;i++) cin>>t[i];
	for (i=0;i<n;i++)
	{
		l[i]=-1;
		r[i]=-1;
		for (j=0;j<s[i].length();j++) if (s[i][j]-t[i][j])
		{
			l[i]=j;
			break;
		}
		for (j=s[i].length()-1;j>=0;j--) if (s[i][j]-t[i][j])
		{
			r[i]=j;
			break;
		}
		if (l[i]>=0) co.push_back(i);
	}
	for (i=1;i<co.size();i++)
	{
		string s1=s[co[i]].substr(l[co[i]],r[co[i]]-l[co[i]]+1);
		string s2=s[co[i-1]].substr(l[co[i-1]],r[co[i-1]]-l[co[i-1]]+1);
		if (s1!=s2)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	for (i=1;i<co.size();i++)
	{
		string s1=t[co[i]].substr(l[co[i]],r[co[i]]-l[co[i]]+1);
		string s2=t[co[i-1]].substr(l[co[i-1]],r[co[i-1]]-l[co[i-1]]+1);
		if (s1!=s2)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	while(true)
	{
		u=0;
	for (i=0;i<co.size();i++)
	{
		if (l[co[i]]==0) 
		{
			u=1; break;
		}
		if (i)
		{
		if (s[co[i]][l[co[i]]-1]-s[co[i-1]][l[co[i-1]]-1])
		{
			u=1; break;
		}
		}
	}
		if (u) break;
	for (i=0;i<co.size();i++)
	{
		l[co[i]]--;
	}
	}
	
	
	while(true)
	{
		u=0;
	for (i=0;i<co.size();i++)
	{
		if (r[co[i]]==s[co[i]].size()-1) 
		{
			u=1; break;
		}
		if (i)
		{
		if (s[co[i]][r[co[i]]+1]-s[co[i-1]][r[co[i-1]]+1])
		{
			u=1; break;
		}
		}
	}
		if (u) break;
	for (i=0;i<co.size();i++)
	{
		r[co[i]]++;
	}
	}
	key=s[co[0]].substr(l[co[0]],r[co[0]]-l[co[0]]+1);
	for (i=0;i<n;i++) check(i);
	cout<<"YES\n";
	cout<<key<<endl;
	cout<<t[co[0]].substr(l[co[0]],r[co[0]]-l[co[0]]+1);
}