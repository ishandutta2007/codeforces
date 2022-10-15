
// Problem : E. Santa Claus and Tangerines
// Contest : Codeforces - Technocup 2017 - Elimination Round 3
// URL : https://codeforces.com/problemset/problem/748/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
#define pll pair<ll,ll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,used[501],arr[1000001],t,t1,i,j,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
vector<ll> gt[33]; pll res[33];
void dfs(ll cur, ll dir,ll x, ll y, ll lay)
{
	res[cur]={x,y};
	used[cur]=1;
	ll po=0;
	for (int i=0;i<gt[cur].size();i++)
	{
		ll tar=gt[cur][i];
		if (!used[tar])
		{
			if ((dir<4)and(po==(dir+2)%4)) po++;
			if (po==4)
			{
				cout<<"NO";
				exit(0);
			}
			dfs(tar,po,x+dx[po]*pow(2,30-lay),y+dy[po]*pow(2,30-lay),lay+1);
			po++;
		}
	}
}
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=1;i<n;i++)
    {
    	cin>>m>>k;
    	gt[m].push_back(k);
    	gt[k].push_back(m);
    }
    dfs(1,4,0,0,0);
    cout<<"YES\n";
    for (i=1;i<=n;i++)
    cout<<res[i].fi<<' '<<res[i].se<<endl;
    cout<<endl;
}