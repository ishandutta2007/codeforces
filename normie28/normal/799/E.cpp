/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "path.inp"
#define FILE_OUT "path.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MAX 300001
#define mag 320
#define mp make_pair
#define X first
#define Y second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
const int N=200008;
const int M=1000000008;
int n,m,w,c[N],d[N];
multiset<int>a[4],ext;
int main()
{
	ll ans,s;
	int i,j,k,nn,ns,p1,p2;
	cin>>n>>m>>w;
	for(i=1;i<=n;i++) cin>>c[i];
	cin>>j;while(j--){cin>>k;d[k]|=1;}
	cin>>j;while(j--){cin>>k;d[k]|=2;}
	s=0;
	for(i=1;i<=n;i++){a[d[i]].insert(c[i]);if(d[i]<3)s+=c[i];}
	nn=n-(int)a[3].size();ns=0;
	ans=1ll<<60;
	do
	{
		while(!ext.empty())
		{
			p1=p2=0;
			if(!a[1].empty()&&(int)a[1].size()>w-ns&&*--a[1].end()>*ext.begin()&&*--a[1].end()>p1){p1=*--a[1].end();p2=1;}
			if(!a[2].empty()&&(int)a[2].size()>w-ns&&*--a[2].end()>*ext.begin()&&*--a[2].end()>p1){p1=*--a[2].end();p2=2;}
			if(p1){s=s-p1+*ext.begin();a[p2].erase(--a[p2].end());a[0].insert(*ext.begin());ext.erase(ext.begin());}
			else break;
		}
		while(nn>m)
		{
			p1=0;
			if(!a[1].empty()&&(int)a[1].size()>w-ns&&*--a[1].end()>p1){p1=*--a[1].end();p2=1;}
			if(!a[2].empty()&&(int)a[2].size()>w-ns&&*--a[2].end()>p1){p1=*--a[2].end();p2=2;}
			if(!a[0].empty()&&*--a[0].end()>p1){p1=*--a[0].end();p2=0;}
			if(p1==0)break;
			else{nn--;s-=p1;a[p2].erase(--a[p2].end());if(p2==0)ext.insert(p1);}
		}
		if(nn==m&&(int)a[1].size()>=w-ns&&(int)a[2].size()>=w-ns&&s<ans)ans=s;
		if(a[3].empty())break;
		nn++;ns++;s+=*a[3].begin();a[3].erase(a[3].begin());
	}while(ns<=m);
	if(ans==(1ll<<60)) cout<<-1;
	else cout<<ans;
}