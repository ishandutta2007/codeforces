//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const ll mod=1000*1000*1000+7;

const int maxn=1000*1000+7, alfa=26;
int len[maxn], link[maxn], to[maxn][alfa], slink[maxn], diff[maxn];
int sz, last, n;
char s[maxn];

void init() {
	s[n++]=len[1]=-1;
	link[0]=1;
	sz=2;
}
int get_link(int v) {
	while(s[n-len[v]-2]!=s[n-1]) v=link[v];
	return v;
}
void add_letter(char c) {
	s[n++]=c-='a';
	last=get_link(last);
	if(!to[last][c]) {
		len[sz]=len[last]+2;
		link[sz]=to[get_link(link[last])][c];
		diff[sz]=len[sz]-len[link[sz]];
		slink[sz]=(diff[sz]==diff[link[sz]] ? slink[link[sz]] : link[sz]);
		to[last][c]=sz++;
	}
	last=to[last][c];
}

const int nax=1e6+7;
int m;
char wcz[nax];
char tekst[nax];

ll dp[nax];
ll serdp[nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main() {
	scanf("%s", wcz+1);
	m=strlen(wcz+1);
	for (int i=1; i<=m/2; i++)
	{
		tekst[2*i-1]=wcz[i];
		tekst[2*i]=wcz[m+1-i];
	}
	init();
	dp[0]=1;
	for(int i=1; i<=m; i++) {
		add_letter(tekst[i]);
		for(int v=last; len[v]>0; v=slink[v]) {
			serdp[v]=dp[i-(len[slink[v]]+diff[v])];
			if(diff[v] == diff[link[v]])
				dod(serdp[v], serdp[link[v]]);
			if (!(i&1)) {
				dod(dp[i], serdp[v]);
			}
		}
	}
	printf("%lld\n", dp[m]);
}