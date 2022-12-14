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

const int MAXN = 105;
const int turn[3][3] = {
                       {1, 0, 0}, 
                       {0, 1, 0}, 
                       {0, 0, 1}
                       };
const int turn2[6][6] = {
                       {1, 0, 0, 0, 1, 0},
                       {1, 0, 0, 0, 0, 1},
                       {0, 1, 0, 1, 0, 0},
                       {0, 1, 0, 0, 0, 1},
                       {0, 0, 1, 1, 0, 0},
                       {0, 0, 1, 0, 1, 0}
                       };

char s[MAXN][MAXN][MAXN];
int n, m, k;

bool ok(int x, int y, int z)
{
 	return x >= 0 && y >= 0 && z >= 0 && x < n && y < m && z < k && s[x][y][z] == '1';
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	scanf("%d%d%d\n", &n, &m, &k);	
	forn (i, n)
	{
		forn (j, m)
			gets(s[i][j]);
		scanf(" ");
	}
	int ans = 0;
	forn (i, n)
		forn (j, m)
			forn (g, k)
				if (s[i][j][g] == '1')
				{
					bool was = 0;
					forn (l, 3)
						if (ok(i - turn[l][0], j - turn[l][1], g - turn[l][2]) 
						 && ok(i + turn[l][0], j + turn[l][1], g + turn[l][2]))
						{
							ans++;
							was = 1;
							break;
						}
					if (was)	
						continue;
					forn (l, 6)
						if (ok(i - turn2[l][0], j - turn2[l][1], g - turn2[l][2]) 
						 && ok(i + turn2[l][3], j + turn2[l][4], g + turn2[l][5])
						&& !ok(i - turn2[l][0] + turn2[l][3], j - turn2[l][1] + turn2[l][4], g - turn2[l][2] + turn2[l][5]))
						{
							ans++;
							was = 1;
							break;
						}					
				}
	printf("%d\n", ans);
	return 0;
}