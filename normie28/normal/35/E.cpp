

// Problem : E. Parade
// Contest : Codeforces - Codeforces Beta Round #35 (Div. 2)
// URL : https://codeforces.com/problemset/problem/35/E
// Memory Limit : 64 MB
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
#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
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
const int Max = 5e5 + 3, Mod = 1e9 + 7;
 
const int N = 5e5 + 10, mod = 7340033.;
 
int n;
typedef pair<int, int> p2;
vector<p2> ans;
multiset<int> s;
vector<pair<p2, int>> v;
 
bool cmp(pair<p2, int>& a, pair<p2, int>& b)
{
	int x1 = a.first.first, t1 = a.first.second, h1 = a.second;
	int x2 = b.first.first, t2 = b.first.second, h2 = b.second;
	if (x1 != x2)
		return x1 < x2;
	if (t1 != t2)
		return t1 < t2;
	if (t1)
		return h1 > h2;
	return h1 < h2;
 
}
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r, h;
		cin >> h >> l >> r;
		v.push_back({ {l,0},-h });
		v.push_back({ {r,1},h });
	}
	sort(v.begin(), v.end());
	int x = -2e9, y = 0;
	s.insert(0);
	for (auto i : v)
	{
		int X = i.first.first;
		int t = i.first.second;
		int h = abs( i.second) ;
		if (t == 0)
		{
			s.insert(h);
			if (x < X && y < h)
			{
				ans.push_back({ X,y });
				ans.push_back({ X,h });
				x = X;
				y = h;
			}
		}
		else
		{
			s.erase(s.find(h));
			int mx = *s.rbegin();
			if (mx < y)
			{
				ans.push_back({ X,y });
				ans.push_back({ X,mx });
				x = X;
				y = mx;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i.first << ' ' << i.second << '\n';
	return 0;
}