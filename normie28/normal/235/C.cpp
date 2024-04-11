
// Problem : C. Cyclical Quest
// Contest : Codeforces - Codeforces Round #146 (Div. 1)
// URL : https://codeforces.com/problemset/problem/235/C
// Memory Limit : 512 MB
// Time Limit : 3000 ms
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
const int N = 2e6 + 9; 
struct State {
	int len, las, val;
	State *go[26], *par;
	State (int len = 0) : len(len), las(0), val(0), par(0) { memset(go, 0, sizeof go); }
}*last, *root, pool[N], *pis = pool, *xl[N];
 
void Extend (int w) {
	State *p = last, *np = new (pis++) State(p->len + 1); np->val = 1;
	while (p && !p->go[w]) p->go[w] = np, p = p->par;
	if (p == 0) {
		np->par = root;
	} else {
		State *q = p->go[w];
		if (p->len + 1 == q->len) {
			np->par = q;
		} else {
			State *nq = new (pis++) State(*q);
			nq->len = p->len + 1; nq->val = 0;
			q->par = np->par = nq;
			while (p && p->go[w] == q) p->go[w] = nq, p = p->par;
		}
	}
	last = np;
}
 
int n, m, c[N];
char s[N];
 
int main () {
	fio;
	cin>>s;
	n = strlen(s);
	last = root = new (pis++) State();
	for (int i = 0; i < n; ++i) Extend(s[i] - 'a');
	m = pis - pool - 1;
	for (State *p = pis - 1; p != root; --p) ++c[p->len];
	for (int i = 1; i <= n; ++i) c[i] += c[i - 1];
	for (State *p = pis - 1; p != root; --p) xl[c[p->len]--] = p;
	for (int i = m; i; --i) {
		if (!xl[i]->val) ++xl[i]->val;
		xl[i]->par->val += xl[i]->val;
	}
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		cin>>s;
		State *p = root;
		m = strlen(s);
		int ans = 0;
		for (int j = 0; j < m; ++j) s[j + m] = s[j];
		for (int j = 0, w, len = 0; j < (m << 1); ++j) {
			w = s[j] - 'a';
			while (p != root && !p->go[w]) p = p->par, len = p->len;
			if (p->go[w]) {
				p = p->go[w]; ++len;
				while (p->par->len >= m) p = p->par, len = p->len;
				if (len >= m && p->las != i) p->las = i, ans += p->val;
			}
		}
		cout<<ans<<endl;
	}
}