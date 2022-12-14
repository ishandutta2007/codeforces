#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAXN = 1e5 + 5, MAX_LEN = 42;

char s[MAX_LEN];
map<string, set<string>> m;
pair<int, string> d[MAXN];
pair<set<string>, string> c[MAXN];
vector<vector<string>> ans;

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	scanf("%d\n", &n);
	forn (i, n)
	{
		gets(s);
		int len = strlen(s);
		int last = len;
		forab (i, 7, len)
			if (s[i] == '/')
			{
			 	last = i;
			 	break;
			}
		string t = "", r = "";
		forab (i, last, len)
			t += s[i];
		forn (i, last)
			r += s[i];
		m[r].insert(t);
	}	
	int it = 0;
	for (auto np : m)
		d[it] = mp(sz(np.sc), np.fs), it++;
	int l = sz(m);
	sort(d, d + l);
	forn (i, l)
	{
		int last = l;
		forab(j, i, l)
			if (d[j].fs != d[i].fs)
			{
			 	last = j;
			 	break;
			}
		forab (j, i, last)
			c[j] = mp(m[d[j].sc], d[j].sc);
		sort(c + i, c + last);
		int cur = i;
		forab (j, i + 1, last)
			if (c[j].fs != c[j - 1].fs)
			{
				if (cur != j - 1)
				{
				    vector <string> v;
					forab (g, cur, j)
						v.pb(c[g].sc);
					ans.pb(v);
				}
				cur = j;
			}
   		if (cur != last - 1)
   		{
   		    vector <string> v;
   			forab (g, cur, last)
   				v.pb(c[g].sc);
   			ans.pb(v);
   		}
   		i = last - 1;
	}
	printf("%d\n", sz(ans));
	for (auto &v : ans)
	{
		for (auto s : v)
			printf("%s ", s.c_str()); 
		puts("");
	}
	return 0;
}