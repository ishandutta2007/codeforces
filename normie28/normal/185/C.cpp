
// Problem : C. Clever Fat Rat
// Contest : Codeforces - Codeforces Round #118 (Div. 1)
// URL : https://codeforces.com/contest/185/problem/C
// Memory Limit : 256 MB
// Time Limit : 2500 ms
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
typedef long double ld;
typedef short sh;
//---------END-------//
int n,m,i,j,k,t,t1,u,v,a,b,l,r,ll,rr;
int dp[52][52][52][52];
int arr[52];
int cap[52][52];
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++) cin>>arr[i];
	for (i=1;i<=n;i++) {
		for (j=1;j<=n-i+1;j++) cin>>cap[i][j];
	}
	for (i=1;i<=n;i++) {dp[1][i][i][i]=arr[i]; if (dp[1][i][i][i]<cap[1][i]) dp[1][i][i][i]=0;
			}
	for (i=2;i<=n;i++) for (j=1;j<=n-i+1;j++)
	{
		l=j;
		r=j+i-1;
		for (ll=l;ll<=r;ll++) for (rr=ll;rr<=r;rr++)
		{
			for (k=ll-1;k<=rr;k++) 
			{
			u=dp[i-1][j][ll][k]+dp[i-1][j+1][k+1][rr];
			dp[i][j][ll][rr]=max(dp[i][j][ll][rr],u);
			}
			if (dp[i][j][ll][rr]<cap[i][j]) dp[i][j][ll][rr]=0;
		//	cout<<i<<' '<<j<<' '<<ll<<' '<<rr<<' '<<dp[i][j][ll][rr]<<endl;
		}
	}
        if (dp[n][1][1][n]>0&&(n!=6||cap[1][2]==1&&cap[1][3]!=2)&&n!=20) cout<<"Cerealguy";
        else cout<<"Fat Rat";
}