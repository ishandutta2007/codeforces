//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
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
const int nax=1000*1007;
const int n1=(1<<17);
const int d=14;
const int inf=1e9;

int n, q;

char wcz[nax];

vector<vector<string>> wek;

int mac[d][d];

int podc(string nad, string pod)
{
	for (int i=0; i+(int)pod.size()<=(int)nad.size(); i++)
	{
		int ok=1;
		for (int j=0; j<(int)pod.size(); j++)
			if (pod[j]!=nad[i+j])
				ok=0;
		if (ok)
			return 1;
	}
	return 0;
}

int drz[nax][d];

void ustal(int v, int x)
{
	v+=n1-1;
	for (int i=0; i<d; i++)
		drz[v][i]=inf;
	drz[v][1+x]=0;
	drz[v][1+(x+1)%3]=1;
	drz[v][1+(x+2)%3]=1;
	v>>=1;
	while(v)
	{
		for (int i=0; i<d; i++)
			drz[v][i]=inf;
		for (int i=0; i<d; i++)
			for (int j=0; j<d; j++)
				drz[v][mac[i][j]]=min(drz[v][mac[i][j]], drz[2*v][i]+drz[2*v+1][j]);
		v>>=1;
	}
}

int main()
{
	wek.push_back(vector<string>(0));
	wek.push_back(vector<string>{"a"});
	wek.push_back(vector<string>{"b"});
	wek.push_back(vector<string>{"c"});
	wek.push_back(vector<string>{"a", "c"});
	wek.push_back(vector<string>{"a", "b"});
	wek.push_back(vector<string>{"b", "c"});
	wek.push_back(vector<string>{"a", "b", "c"});
	wek.push_back(vector<string>{"ab"});
	wek.push_back(vector<string>{"bc"});
	wek.push_back(vector<string>{"ab", "c"});
	wek.push_back(vector<string>{"a", "bc"});
	wek.push_back(vector<string>{"ab", "bc"});
	wek.push_back(vector<string>{"abc"});
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<d; j++)
		{
			vector<string> now;
			for (string a : wek[i])
				now.push_back(a);
			for (string a : wek[j])
				now.push_back(a);
			vector<string> lew=wek[i];
			vector<string> pra=wek[j];
			for (string s : wek[i])
			{
				if (s=="ab")
					lew.push_back("a");
				if (s=="bc")
					lew.push_back("c");
			}
			for (string s : wek[j])
			{
				if (s=="ab")
					pra.push_back("a");
				if (s=="bc")
					pra.push_back("c");
			}
			for (string a : lew)
				for (string b : pra)
					if (podc("abc", a+b))
						now.push_back(a+b);
			sort(now.begin(), now.end());
			vector<string> tmp=now;
			now.clear();
			while(!tmp.empty())
			{
				string s=tmp.back();
				tmp.pop_back();
				int ok=1;
				for (string i : tmp)
					if (podc(i, s))
						ok=0;
				for (string i : now)
					if (podc(i, s))
						ok=0;
				if (ok)
					now.push_back(s);
			}
			sort(now.begin(), now.end());
			int g=-1;
			for (int l=0; l<d; l++)
				if (now==wek[l])
					g=l;
			assert(g>=0);
			mac[i][j]=g;
		}
	}
	for (int i=1; i<2*n1; i++)
		for (int j=0; j<d; j++)
			drz[i][j]=inf*(j>0);
	scanf("%d%d", &n, &q);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		ustal(i, wcz[i]-'a');
	while(q--)
	{
		int a;
		char c;
		scanf("%d %c", &a, &c);
		ustal(a, c-'a');
		int wyn=inf;
		for (int i=0; i+1<d; i++)
			wyn=min(wyn, drz[1][i]);
		printf("%d\n", wyn);
	}
	return 0;
}