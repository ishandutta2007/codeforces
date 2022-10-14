#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std; 
typedef long long ll;
typedef long double ld;

//aho corasick
//lowercase english letters, words only for unique words
//ends of occurances in res vector : <id, where>

struct aho {
	vector <vector <int> > graf;
	vector <int> up, word, rob, znak, found;
	vector <pair <int, int> > depth;
	aho() {
		rob.resize(27, -1);
		graf.pb(rob);
		up.pb(-1);
		found.pb(-1);
		word.pb(-1);
		znak.pb('#');
	}
	int suf (int a, int b) {
		while (a>=0) {
			if (graf[a][b]!=-1) return graf[a][b];
			a = up[a];
		}
		return 0;
	}
	void add (string &s, int id, int a=0)  {
		rep(pos,0,(int)s.size()) {
			if (graf[a][s[pos]-'a']==-1) {
				graf[a][s[pos]-'a']=(int)up.size();
				depth.pb(mp(pos, (int)up.size()));
				up.pb(a);
				znak.pb(s[pos]-'a');
				word.pb(-1);
				found.pb(-1);
				graf.pb(rob);
			}
			a = graf[a][s[pos]-'a'];
		}
		word[a] = id;
	}
	//preprocessing
	void ups () {
		sort(depth.begin(), depth.end());
		for (pair <int, int> p: depth) {
			up[p.se]=suf(up[up[p.se]], znak[p.se]);
			found[p.se] = word[up[p.se]]>=0 ? up[p.se] : found[up[p.se]];
		}
	}
	//pattern search
	int walk (string &s, vector <vector <int> > &res, int a=0) {
		rep(pos,0,(int)s.size()) {
			while (a>0 && graf[a][s[pos]-'a']<0) a = up[a];
			a = max(0,graf[a][s[pos]-'a']);
			int b=a;
			do {if (word[b]>=0) res[word[b]].pb(pos);} 
			while ((b = found[b])>=0);
		}
		return (int)res.size();
	}
};

const int N = 1e5+100;
int K[N], Len[N];

int main ()
{
	aho H;
	string s, t;
	int n;
	cin>>t >>n;
	rep(i,0,n)
	{
		cin>>K[i] >>s;
		Len[i] = s.size();
		H.add(s,i);
	}
	
	H.ups();
	

	vector <vector <int> > res(n);
	H.walk(t,res);
	rep(query,0,n)
	{
		
		if ((int)res[query].size() < K[query]) printf ("-1\n");
		else
		{
			int best = t.size();
			rep(i,0,(int)res[query].size() - K[query] +1)
			{
				best = min(best, res[query][i+K[query]-1] - res[query][i] + Len[query]);
			}
			
			printf ("%d\n", best);
		}
	}
}