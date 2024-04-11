
// Problem : G. Divisor Set
// Contest : Codeforces - Educational Codeforces Round 76 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1257/problem/G
// Memory Limit : 512 MB
// Time Limit : 5000 ms
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
#define pb push_back
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
const int maxn = 2e5 + 20;
const int mod = 998244353;
 
int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);
 
	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;
 
	return x;
}
 
void rev(vector<int> &a)
{
	int N = a.size() , maxb = __builtin_ctz(N);
	for(int i = 0; i < N; i++)
	{
		int k = 0;
		for(int j = 0; j < maxb; j++)
			if((i >> j) & 1)
				k |= (1 << (maxb - 1 - j));
 
		if(i < k)
			swap(a[i] , a[k]);
	}
}
 
void mul(vector<int> &a , int val)
{
	int N = a.size();
	assert((N&(-N)) == N);
	rev(a);
 
	for(int len = 2; len <= N; len *= 2)
	{
		int wn = bpw(3 , (mod - 1) / len);
		if(val == -1)
			wn = bpw(wn , mod - 2);
		for(int i = 0; i < N; i += len)
		{
			int nxt = len / 2 , pw = 1;
			for(int j = 0; j < nxt; j++)
			{
				int x = a[i + j] , y = a[i + j + nxt];
				a[i + j] = (x + 1LL * pw * y) % mod;
				a[i + j + nxt] = (x - 1LL * pw * y % mod + mod) % mod;
				pw = 1LL * pw * wn % mod;
			}
		}
	}
 
	if(val == -1)
	{
		int inv = bpw(N , mod - 2);
		for(int i = 0; i < N; i++)
			a[i] = 1LL * a[i] * inv % mod;
	}
}
 
int get(int k)
{
	int N = 1;
	while(N < k)
		N *= 2;
	
	return N;
}
 
vector<int> operator * (vector<int> a , vector<int> b)
{
	if(a.size() < b.size())
		a.swap(b);
 
	int N = get(a.size() + b.size());
	a.resize(N) , b.resize(N);
 
	if(N <= 300)
	{
		vector<int> ans;
		ans.resize(N);
		for(int i = 0; i < N; i++)
			for(int j = 0; i + j < N; j++)
				ans[i + j] = (ans[i + j] + 1LL * a[i] * b[j]) % mod;
 
		while(!ans.empty() && !ans.back())
			ans.pop_back();
 
		return ans;
	}
 
	mul(a , 1) , mul(b , 1);
	for(int i = 0; i < N; i++)
		a[i] = 1LL * a[i] * b[i] % mod;
	mul(a , -1);
 
	while(!a.empty() && !a.back())
		a.pop_back();
 
	return a;
}
 
vector<int> a[maxn];
 
vector<int> solve(int s , int e)
{
	if(e - s < 2)
		return a[s];
 
	int m = (s + e) / 2;
	return solve(s , m) * solve(m , e);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int n;
	cin >> n;
 
	map<int , int> mp;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
	}
 
	int cnt = 0;
	map<int , int> mp2;
	for(auto x : mp)
		mp2[x.second]++;
 
	cnt = 0;
	for(auto x : mp2)
	{
		vector<int> tmp(get((x.first + 1) * x.second));
		for(int i = 0; i <= x.first; i++)
			tmp[i] = 1;
 
		mul(tmp , 1);
		for(int i = 0; i < (int)tmp.size(); i++)
			tmp[i] = bpw(tmp[i] , x.second);
		mul(tmp , -1);
 
		while(!tmp.empty() && !tmp.back())
			tmp.pop_back();
 
		a[cnt++] = tmp;
	}
 
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(a , a + cnt , rng);
 
	cout << solve(0 , cnt)[n / 2] << endl;
}