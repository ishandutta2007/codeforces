
// Problem : E. Short Code
// Contest : Codeforces - Codeforces Round #476 (Div. 2) [Thanks, Telegram!]
// URL : https://codeforces.com/problemset/problem/965/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
struct node
{
	node *child[27];
	bool end;
	priority_queue<int> pq;
	node()
	{
		memset(child, 0, sizeof child);
		end = 0;
	}
};
int n;
node *root = new node();
void insert(string &s)
{
	node *cur = root;
	for (int i = 0; i < s.size(); i++)
	{
		if (!cur->child[s[i] - 'a'])
			cur->child[s[i] - 'a'] = new node();
		cur = cur->child[s[i] - 'a'];
	}
	cur->end = 1;
}
int solve(node *cur, int lvl)
{
	for (int i = 0; i < 26; i++)
	{
		if (!cur->child[i])
			continue;
		solve(cur->child[i], lvl + 1);
		while (cur->child[i]->pq.size())
		{
			cur->pq.push(cur->child[i]->pq.top());
			cur->child[i]->pq.pop();
		}
	}
	if (!lvl)
	{
		int ret = 0;
		while (cur->pq.size())
			ret += cur->pq.top(), cur->pq.pop();
		return ret;
	}
	if (!cur->end)
	{
		if (cur->pq.size())
		{
			cur->pq.pop();
			cur->pq.push(lvl);
		}
	}
	else
		cur->pq.push(lvl);
	return 0;
}
int main()
{
	fio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		insert(s);
	}
	cout << solve(root, 0) << endl;
}