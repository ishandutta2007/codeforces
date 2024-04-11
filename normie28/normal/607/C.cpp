
// Problem : C. Marbles
// Contest : Codeforces - Codeforces Round #336 (Div. 1)
// URL : https://codeforces.com/problemset/problem/607/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// powwered by CP Editor (https://github.com/cpeditor/cpeditor)

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
const int B = 4267;
const int MOD = 1e9 + 33;
const int MN = 1e6 + 44;
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef pair <long long, int> hash_t;
//---------END-------//
char a[MN], b[MN];
long long poww[MN];
hash_t nill = make_pair(0LL, 0);
hash_t lex(hash_t a, char b)
{
	return make_pair((a.first + b * poww[a.second]) % MOD, a.second + 1);
}
hash_t rex(hash_t a, char b)
{
	return make_pair((a.first * B + b) % MOD, a.second + 1);
}
void err()
{
	cout<<"NO"<<endl;
	exit(0);
}
char opp[128];
int main()
{
	fio;
	int n;
	cin>>n>>a>>b;
	n--;
	poww[0] = 1;
	for (int i = 1; i < n; ++i)
		poww[i] = poww[i - 1] * B % MOD;
	opp['N'] = 'S';
	opp['S'] = 'N';
	opp['E'] = 'W';
	opp['W'] = 'E';
	hash_t A = nill, B = nill;
	for (int i = n - 1; i >= 0; --i)
	{
		A = lex(A, a[i]);
		B = rex(B, opp[b[i]]);
		if (A == B)
			err();
	}
	cout<<"YES";
}