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
typedef long long ll;
#define pi 3.1415926535897
//------START-----------//
vector<int> calc1(int n)
{
//	cout<<"calc1 "<<n<<endl;
	vector<int> res;
	if (n==2) return {2,1};
	if (n%2==1) return {};
	int t=floor(log2(n+2)),i;
	for (i=1;i<=(1<<t)-2;i++)
	res.push_back((1<<t)-1-i);
	if (res.size()==n) return res;
	res.push_back((1<<t));
	res.push_back((1<<t)-1);
	if (res.size()==n) return res;
	for (i=1;i<=n-(1<<t);i++)
	res.push_back((1<<t)-1-i);
	vector<int> res2=calc1(n-(1<<t));
	for (i=0;i<res2.size();i++)
	res[i]=res2[i]+(1<<t);
//	for (int g:res) cout<<g<<' ';
//	cout<<endl;
	return res;
}
vector<int> calc2(int n)
{
//	cout<<"calc2 "<<n<<endl;
	if (log2(n)==floor(log2(n))) return {};
	if (n<=5) return {};
	if (n==6) return {3,6,1,5,4,2};
	if (n==7) return {3,6,1,5,4,7,2};
	int t=floor(log2(n+1));
	if (floor(log2(n+1))==log2(n+1)) t--;
	vector<int> res=calc2((1<<t)-1);
//	for (int g:res) cout<<g<<' '; cout<<endl;
	int left=n-((1<<t)-1);
	int i;
	for (i=0;i<left;i++) res.push_back((1<<t)+(i+1)%left);
	return res;
}
int n,m,i,j,k,used[10];
vector<int> res;

int main() {
	cin>>n;
	vector<int> res1=calc1(n);
	if (res1.size())
	{
		cout<<"YES\n";
		for (int g:res1) cout<<g<<' ';
		cout<<endl;
	}
	else cout<<"NO\n";
	vector<int> res2=calc2(n);
	if (res2.size())
	{
		cout<<"YES\n";
		for (int g:res2) cout<<g<<' ';
		cout<<endl;
	}
	else cout<<"NO\n";
}