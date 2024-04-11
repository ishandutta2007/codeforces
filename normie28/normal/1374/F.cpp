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
ll n,m,i,j,k,t,t1,u,v,a,b,l,r,tarl,tarr;
ll arr[501];
ll per[501];
ll pos[501];
ll lis[501];
vector<ll> ops;
void shft(ll x)
{
	if ((1<=x)and(x+2<=n));
  else
  {
    cout<<x<< " is not suitable!\n";
    exit(0);
  }
	ops.push_back(x);
	pos[per[x]]++;
	pos[per[x+1]]++;
	pos[per[x+2]]-=2;
	swap(per[x+1],per[x+2]);
	swap(per[x],per[x+1]);
}
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
    //  cout<<n<<endl;
		for (i=1;i<=n;i++) 
		{
			cin>>arr[i];
      //    cout<<arr[i]<<' ';
			per[i]=lis[i]=pos[i]=i;
		}
      cout<<endl;
		ops.clear();
		sort(lis+1,lis+n+1,[](ll a, ll b){return (arr[a]<arr[b]);});
		for (i=1;i<n;i++) if (arr[lis[i]]==arr[lis[i+1]]) break;
		v=i;
      l=0;r=0;
		while(l+r+3<n)
		{
			if ((v==n)or(l<v-1))
			{
				u=lis[l+1];
        //      cout<<'l'<<u<<' '<<arr[u]<<' '<<pos[u]<<endl;
				while(pos[u]-(l+1)>=2) shft(pos[u]-2);
				if (pos[u]-(l+1)==1)
				{
					shft(pos[u]-1);
					shft(pos[u]-2);
				}
				l++;
			}
			else
			{
				u=lis[n-r];
        //      cout<<'r'<<u<<' '<<arr[u]<<' '<<pos[u]<<endl;
				while((n-r)-pos[u]) shft(min(pos[u],n-r-2));
				r++;
			}
		}
		for (i=0;i<3;i++)
		{
			if ((arr[per[l+1]]<=arr[per[l+2]])and(arr[per[l+2]]<=arr[per[l+3]])) break;
			shft(l+1);
		}
		if (i==3)
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<ops.size()<<endl;
			for (auto g : ops) cout<<g<<' ';
          cout<<endl;
		}
	}
}