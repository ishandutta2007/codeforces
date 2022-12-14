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

const int MAXN = 100;

int used[MAXN], was[MAXN], inDeg[MAXN];
char s[MAXN];
vi st, g[MAXN];

void dfs(int v)
{
 	used[v] = 1;
 	for (int u : g[v])
 		if (!used[u])
 			dfs(u);
	st.pb(v);
}

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
		forn (j, len)
			was[s[j] - 'a'] = 1;
		forn (j, len - 1)
			g[s[j] - 'a'].pb(s[j + 1] - 'a'), inDeg[s[j + 1] - 'a']++;			
	}	
	forn (i, 26)
		if (was[i] && !used[i] && !inDeg[i])
			dfs(i);
	reverse(all(st));
	for (int k : st)
		printf("%c", 'a' + k);
	return 0;
}