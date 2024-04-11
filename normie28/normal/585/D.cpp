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
#define MOD (ll(1000000000))
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
unordered_map<ll,pair<ll,ll>> mp;
ll p[26][3];
ll summ[3][2];
ll n,m,i,j,k,t,t1,u,v,a,b,cnt[3],res=-1e9,resmas;
ll pw3[26];
int main()
{
	fio;
	cin>>n;
	pw3[0]=1;
	for (i=0;i<n;i++)
	{
		cin>>p[i][0]>>p[i][1]>>p[i][2];
		if (i<n/2)
		{
		summ[0][0]+=p[i][0];
		summ[1][0]+=p[i][1];
		summ[2][0]+=p[i][2];
		}
		else
		{
			
		summ[0][1]+=p[i][0];
		summ[1][1]+=p[i][1];
		summ[2][1]+=p[i][2];
		}
		pw3[i+1]=pw3[i]*3;
	}
	for (i=0;i<pw3[n/2];i++)
	{
		cnt[0]=summ[0][0];
		cnt[1]=summ[1][0];
		cnt[2]=summ[2][0];
		v=i;
		for (j=0;j<n/2;j++)
		{
			cnt[v%3]-=p[j][v%3];
			v/=3;
		}
		u=(cnt[1]-cnt[0]+500000000)*MOD+(cnt[2]-cnt[0]+500000000);
		if ((mp[u].se==0)or(cnt[0]>mp[u].fi))
		{
			mp[u]={cnt[0],i+MOD};
		}
	//	cout<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<endl;
		//	cout<<u<<' '<<cnt[1]<<' '<<i<<endl;
	}
	for (i=0;i<pw3[n-n/2];i++)
	{
		cnt[0]=summ[0][1];
		cnt[1]=summ[1][1];
		cnt[2]=summ[2][1];
		v=i;
		for (j=n/2;j<n;j++)
		{
			cnt[v%3]-=p[j][v%3];
			v/=3;
		}
		u=(cnt[0]-cnt[1]+500000000)*MOD+(cnt[0]-cnt[2]+500000000);
		if ((mp[u].se)and(cnt[0]+mp[u].fi>res))
		{
			res=cnt[0]+mp[u].fi;
			resmas=i*pw3[n/2]+mp[u].se-MOD;
		}
	//	cout<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<endl;
		//	cout<<u<<' '<<cnt[1]<<' '<<i<<endl;
	}
	//cout<<res<<' '<<resmas<<endl;
	if (res==-1e9) cout<<"Impossible";
	else 
	{
		v=resmas;
		for (i=0;i<n;i++)
		{
			if (v%3==0) cout<<"MW\n";
			if (v%3==1) cout<<"LW\n";
			if (v%3==2) cout<<"LM\n";
			v/=3;
		}
	}
}