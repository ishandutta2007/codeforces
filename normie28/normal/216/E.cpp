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
#define FILE_IN "text.out"
#define FILE_OUT "result.out"
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
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
#define vec plv.se
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
ll n,m,k,b,c[1001],t,t1,i,j,minn,maxx,cur=0,lu,lv,sum=0,mul=1;
ll num[100001];
map<ll,vector<ll>> cnt;
int main() {
//	ofile;
	fio;
	cin>>k>>b>>n;
	for (i=1;i<=n;i++) cin>>num[i];
	cnt[0].push_back(0);
	for (i=n;i>=1;i--)
	{
		sum+=num[i];
		if ((b!=0)and(b!=(k-1))) cur+=cnt[(sum-b+(k-1))%(k-1)].size();
		cnt[sum%(k-1)].push_back(sum);
	}
	if ((b==0)or(b==k-1))
	{
		for (pair <ll,vector<ll>> plv: cnt)
		{
			t=1;
			t1=0;
			for (i=1;i<vec.size();i++)
			{
				if (vec[i]==vec[i-1]) t++;
				else 
				{
					t1+=t*(t-1)/2;
					t=1;
				}
			}
			
					t1+=t*(t-1)/2;
					if (b==0) cur+=t1;
					else cur+=ll(vec.size())*(vec.size()-1)/2-t1;
		}
	}
	cout<<cur;
}