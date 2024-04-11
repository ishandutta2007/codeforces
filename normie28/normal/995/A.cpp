
// Problem : A. Tesla
// Contest : Codeforces - Codeforces Round #492 (Div. 1) [Thanks, uDebug!]
// URL : https://codeforces.com/contest/995/problem/A
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define mk_piii(a,b,c) {a,{b,c}}
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n,m,k,c[501],pos[100001],t,t1,i,j,cnt;
int mp[5][101];
vector<piii> moves;
void check (int sa, int sb, int ta, int tb)
{
	
	if ((mp[sa][sb]!=0)and(mp[ta][tb]==0))
	{
	moves.push_back(mk_piii(mp[sa][sb],ta,tb));
	mp[ta][tb]=mp[sa][sb];
	mp[sa][sb]=0;
	}
}
void pus()
{
	for (int i=1;i<=n;i++) 
	{
		if ((mp[2][i]==mp[1][i])and(mp[1][i]))
		{
			moves.push_back(mk_piii(mp[2][i],1,i));
			mp[2][i]=0;
			cnt++;
		}
		if ((mp[3][i]==mp[4][i])and(mp[4][i]))
		{
			moves.push_back(mk_piii(mp[3][i],4,i));
			mp[3][i]=0;
			cnt++;
		}
	}
}
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    for (i=1;i<=4;i++)
    {
    	for (j=1;j<=n;j++) cin>>mp[i][j];
    }
    for (t=1;t<=3*n;t++)
    {
    	pus();
 	  	for (i=1;i<=n;i++) if (i==1) check(2,i,3,i); else check(2,i,2,i-1);
   		pus();
  		for (i=n;i>=1;i--) if (i==n) check(3,i,2,i); else check(3,i,3,i+1);
   		pus();
    } 
    if (cnt<k) cout<<-1;
    else 
    {
    	cout<<moves.size()<<endl;
    	for (piii pp : moves) cout<<pp.p1<<' '<<pp.p2<<' '<<pp.p3<<endl;
    }
}