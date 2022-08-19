//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

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

struct suffix_automaton
{
	vector<map<char,int>> edges; // edges[i]  : the labeled edges from node i
	vector<int> link;            // link[i]   : the parent of i
	vector<int> length;          // length[i] : the length of the longest string in the ith class
	int last;                    // the index of the equivalence class of the whole string

	suffix_automaton(){}
	suffix_automaton(string s)
	{
		// add the initial node
		edges.push_back(map<char,int>());
		link.push_back(-1);
		length.push_back(0);
		last = 0;

		for (int i=0; i<s.size(); i++)
		{
			// construct r
			edges.push_back(map<char,int>());
			length.push_back(i+1);
			link.push_back(0);
			int r = edges.size() - 1;

			// add edges to r and find p with link to q
			int p = last;
			while (p >= 0 && edges[p].find(s[i]) == edges[p].end()) 
			{
				edges[p][s[i]] = r;
				p = link[p];
			}
			if (p != -1)
			{
				int q = edges[p][s[i]];
				if (length[p] + 1 == length[q])
				{
					// we do not have to split q, just set the correct suffix link
					link[r] = q;
				}
				else
				{
					// we have to split, add q'
					edges.push_back(edges[q]); // copy edges of q
					length.push_back(length[p] + 1);
					link.push_back(link[q]); // copy parent of q
					int qq = edges.size()-1;
					// add qq as the new parent of q and r
					link[q] = qq;
					link[r] = qq;
					// move short classes pointing to q to point to q'
					while (p >= 0 && edges[p][s[i]] == q)
					{
						edges[p][s[i]] = qq;
						p = link[p];
					}
				}
			}
			last = r;
		}
	}
};

const int nax=20*1007;

suffix_automaton x;

string s1, s2;

long long dp[nax];
int bylo[nax];

int gdz[nax];

int wyn=nax;

inline void dfs(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (auto i : x.edges[v])
	{
		dfs(i.second);
		dp[v]+=dp[i.second];
	}
	if (v)
		gdz[x.link[v]]|=gdz[v];
}

int main()
{
	cin >> s1 >> s2;
	x=suffix_automaton(s1+"#"+s2);
	int v;
	v=0;
	for (char c : s1)
	{
		v=x.edges[v][c];
		gdz[v]|=1;
	}
	v=0;
	for (char c : s2)
	{
		v=x.edges[v][c];
		gdz[v]|=2;
	}
	v=x.last;
	while(v)
	{
		dp[v]++;
		v=x.link[v];
	}
	dfs(0);
	for (int i=1; i<(int)x.link.size(); i++)
		if (gdz[i]==3 && dp[i]==2)
			wyn=min(wyn, x.length[x.link[i]]+1);
	if (wyn==nax)
		wyn=-1;
	printf("%d\n", wyn);
	return 0;
}