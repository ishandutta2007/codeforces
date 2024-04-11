
// Problem : C. Pekora and Trampoline
// Contest : Codeforces - Codeforces Global Round 13
// URL : https://codeforces.com/contest/1491/problem/C
// Memory Limit : 256 MB
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
ll arr[100011],nxt[100011];
ll n,m,i,j,k,t,t1,u,v,a,b,summ,prv;
vector<ll> bruh;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		summ=0;
		for (i=1;i<=n;i++)
		{
			cin>>arr[i];
			summ+=arr[i];
		}
		for (i=n+1;i>=1;i--)
		{
			if ((arr[i]==1)and(i<=n)) nxt[i]=nxt[i+1];
			else nxt[i]=i;
		}
		a=0;
		while(true)
		{
			if (summ==n) break;
			u=1;
			bruh.clear();
			while(u<=n)
			{
		//		cout<<"u= "<<u<<endl;
		//		cout<<"arr[u]= "<<arr[u]<<endl;
				v=u+arr[u];
				arr[u]--; 
				summ--;
				if (!arr[u])
				{
					summ++;
					arr[u]++;
					v=nxt[u];
				}
				else
				{
					bruh.push_back(u);
					for (j=u;j>=1;j--) if (arr[j]==1) 
					{
						nxt[j]=nxt[j+1];
					}
					else break;
				}
				prv=u;
				u=v;
		//		cout<<"v= "<<v<<endl;
			}
			a++;
			if (summ==n) break;
			if ((bruh.size()==1)and(bruh[0]==prv))
			{
				v=max(0,arr[prv]+prv-(n+1));
				a+=v;
				summ-=v;
				arr[prv]-=v;
			}
			if (summ==n) break;
		//	for (j=1;j<=n;j++) cout<<arr[j]<<' '; cout<<endl;
	//	cout<<endl;
		}
	//	cout<<endl;
		cout<<a<<endl;
	//	cout<<endl;
	}
}