/*
khoi orz, go check out his algo
-normie-
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "robot.inp"
#define FILE_OUT "robot.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 1048576
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define ll long long
#define pi 3.1415926535897
//------START-----------//
//------END-----------//
ll n,m,k,t,t1,i,j,a,b,col[100001], res=0,resi,resj,arr[100001];
ll par[100001];
vector<ll> l,nl;
ll ge (ll x)
{
	if (col[x]) return col[x];
	else return col[x]=ge(par[x])+1;
}
int main()
{
//	ofile;
	fio;
	cin>>n;
	for (i=1;i<=n;i++) cin>>arr[i];
	for (i=2;i<=n;i++) cin>>par[i];
	col[1]=1;
	for (i=1;i<=n;i++) ge(i);
	a=0;
	for (i=1;i<=n;i++) a=max(a,col[i]);
	for (i=1;i<=n;i++) if (col[i]%2==a%2)
	{
		l.push_back(arr[i]);
	}
	else nl.push_back(arr[i]);
///	for (ll g:l) cout<<g<<' ';
////	cout<<endl;
//	for (ll g:nl) cout<<g<<' ';
	sort(nl.begin(),nl.end());
	a=0;
	for (ll g: l) a^=g;
//	cout<<endl<<a<<endl;
	if (a==0)
	{
		res+=l.size()*(l.size()-1)/2;
		res+=nl.size()*(nl.size()-1)/2;
		for (ll g: l) res+=upper_bound(nl.begin(),nl.end(),g)-lower_bound(nl.begin(),nl.end(),g);
	}
	else
	{
		for (ll g: l) {
//			cout<<(g^a)<<endl;
		res+=upper_bound(nl.begin(),nl.end(),g^a)-lower_bound(nl.begin(),nl.end(),g^a);
//		cout<<res<<endl;
		}
	}
	cout<<res;
}