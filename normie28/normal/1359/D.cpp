
// Problem : D. Yet Another Yet Another Task
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/D
// Memory Limit : 512 MB
// Time Limit : 1500 ms
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
ll n,m,k,arr[100001],presum[100001],premin[100001][20],t,t1,i,j,res=-1e18;
vector<ll> st;
ll get_min(ll l, ll r)
{
	ll t=floor(log2(r-l+1));
	ll res=min(premin[l][t],premin[r-(1<<t)+1][t]);
	return res;
}
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=1;i<=n;i++)
    {
    	cin>>arr[i];
    	presum[i]=presum[i-1]+arr[i];
    	premin[i][0]=presum[i];
    }
    for (i=1;i<=floor(log2(n+1));i++)
    for (j=0;j<=n;j++)
    {
    	if (j+(1<<(i-1))<=n) premin[j][i]=min(premin[j][i-1],premin[j+(1<<(i-1))][i-1]);
    	else premin[j][i]=premin[j][i]=min(premin[j][i-1],premin[n-(1<<(i-1))+1][i-1]);
    }
    arr[0]=1e18;
    st.push_back(0);
    for (i=1;i<=n;i++)
    {
    	while ((st.size())and(arr[st[st.size()-1]]<=arr[i])) st.pop_back();
    	st.push_back(i);
    	for (j=0;j<st.size()-1;j++)
    	{
    		ll cur=get_min(st[j],st[j+1]-1);
  //  		cout<<presum[i]-cur<<' '<<arr[st[j+1]]<<endl;
    		cur+=arr[st[j+1]];
    		res=max(res,presum[i]-cur);
    	}
    }
    cout<<res;
}