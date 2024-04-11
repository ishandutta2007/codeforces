
// Problem : D. Parcels
// Contest : Codeforces - Codeforces Round #274 (Div. 1)
// URL : https://codeforces.com/contest/480/problem/D
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

const int N = (int)7e4 + 228;
 
int n, s, f[N];
bitset < N > pref, nxt, b;
pair < int, int > a[N];
vector < int > res[N];
bool was[N];
 
bool cmp(pair < int, int > a, pair < int, int > b)
{
	return a.second < b.second;
}
 
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].first), a[i].second = i;
	pref[0] = true;	
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
	{
		nxt = (pref | (pref << a[i].first));
		b = (nxt ^ pref);
		for (int j = b._Find_first(); j <= s; j = b._Find_next(j))
		{
			f[j] = a[i].second;
		}
		pref = nxt;
	}
	if (a[n].first > s || !pref[s - a[n].first])
	{
		cout << -1 << endl;
		return 0;		
	}
	s -= a[n].first;
	sort(a + 1, a + n + 1, &cmp);
	while(s > 0)
	{
		was[f[s]] = true;
		s -= a[f[s]].first;
	}
	sort(a + 1, a + n + 1);
	int last = -1;
	for (int i = 1; i <= n; i++)
	{
		if (!was[a[i].second])
		{
			if (last != -1)
				res[a[i].second].push_back(last);
			last = a[i].second;
		}	
	}
	sort(a + 1, a + n + 1, &cmp);
	for (int i = 1; i <= n; i++)
	{
		if (res[i].empty())
			printf("%d", a[i].first);
		else
			printf("%d", a[i].first - a[res[i][0]].first);
		printf(" %d ", (int)res[i].size());
		for (int j = 0; j  < (int)res[i].size(); j++)
			printf("%d ", res[i][j]);
		printf("\n");	
	}
 
 
	return 0;
}