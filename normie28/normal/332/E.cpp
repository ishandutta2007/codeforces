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
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,decltype(cmp),rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
 
const int Maxn = 1000006;
const int Maxk = 2005;
 
char p[Maxn];
int plen;
char s[Maxn];
int slen;
int k;
vector <char> gives[Maxk];
vector <char> getfrom[Maxk];
string res = "-";
 
int main()
{
    fio;
	cin.getline(p, Maxn); plen = strlen(p);
	cin.getline(s, Maxn); slen = strlen(s);
	cin>>k;
	for (int i = 0; i < k; i++)
		for (int j = i; j < plen; j += k)
			gives[i].push_back(p[j]);
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < k; j++) getfrom[j].clear();
		for (int j = 0; j < slen; j++)
			getfrom[j % i].push_back(s[j]);
		string cand(k, '0');
		int cur = i - 1;
		for (int j = k - 1; j >= 0 && cur >= 0; j--)
			if (gives[j] == getfrom[cur]) { cand[j] = '1'; cur--; }
		if (cur < 0 && (res == "-" || cand < res)) res = cand;
	}
	cout<<(( res == "-")? ("0"): (res.c_str()));
	
}