//while (clock()<=69*CLOCKS_PER_SEC)
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

const int nax=1000*1007;

int nn;

char sta[nax];
char now[nax];

char tek[nax];


const int maxn=1000*1000+7, alfa=26;
int len[maxn], link[maxn], to[maxn][alfa], slink[maxn], diff[maxn];
int ans[maxn], z[maxn], sz, last, n;
pair <int,int> series_ans[maxn];
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

int main()
{
	scanf("%s", sta);
	scanf("%s", now);
	nn=strlen(sta);
	for (int i=0; i<nn; i++)
	{
		tek[2*i]=sta[i];
		tek[2*i+1]=now[i];
	}
	nn*=2;
	for (int i=nn; i; i--)
		tek[i]=tek[i-1];
	for (int i=1; i<=nn; i++)
		ans[i]=nax;
	
	init();
	for(int i=1; i<=nn; i++) {
		add_letter(tek[i]);
		for(int v=last; len[v]>0; v=slink[v]) {
			series_ans[v] = {ans[i - (len[slink[v]] + diff[v])], i - (len[slink[v]] + diff[v])};
			if(diff[v] == diff[link[v]])
				series_ans[v] = min(series_ans[v], series_ans[link[v]]);
			if (!(i&1)) {
				if (series_ans[v].first+1<ans[i]) {
					ans[i] = series_ans[v].first + 1;
					z[i] = series_ans[v].second;
				}
			}
		}
		if (!(i&1) && tek[i]==tek[i-1] && ans[i-2]<ans[i]) {
			ans[i]=min(ans[i], ans[i-2]);
			z[i]=i-2;
		}
	}
    if (ans[nn]>=nax)
    {
		printf("-1\n");
		return 0;
	}
    printf("%d\n", ans[nn]);
	while(nn)
	{
		if (z[nn]+2==nn)
		{
			
		}
		else
		{
			printf("%d %d\n", z[nn]/2+1, nn/2);
		}
		nn=z[nn];
	}
	return 0;
}