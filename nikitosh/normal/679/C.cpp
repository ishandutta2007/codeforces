#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 505;
const int turn[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char s[MAX_N];
int a[MAX_N][MAX_N], used[MAX_N][MAX_N], num[MAX_N * MAX_N], cnt[MAX_N * MAX_N];
int size = 0;

bool good(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}	

void dfs(int x, int y, int c, int n) {
	used[x][y] = c;
	size++;
	forn (i, 4) {
	 	int dx = x + turn[i][0], dy = y + turn[i][1];
	 	if (good(dx, dy, n) && !a[dx][dy] && !used[dx][dy])
	 		dfs(dx, dy, c, n);
	}	
}

void handleIn(int x, int y, int &sum, int &zero, bool sq) {
	if (!a[x][y]) {
		cnt[used[x][y]]++;
		if (cnt[used[x][y]] == 1) 
			sum += num[used[x][y]];
	} else if (sq)
		zero++;	
}

void handleOut(int x, int y, int &sum, int &zero, bool sq) {
	if (!a[x][y]) {
		cnt[used[x][y]]--;
		if (cnt[used[x][y]] == 0) 
			sum -= num[used[x][y]];
	} else if (sq)
		zero--;	
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, k;
	scanf("%d%d\n", &n, &k);
	forn (i, n) {
		gets(s);
		forn (j, n)
			if (s[j] == '.')
				a[i][j] = 0;
			else
				a[i][j] = 1;
	}
	int color = 0;	
	forn (i, n)
		forn (j, n)
			if (!a[i][j] && !used[i][j]) {
				size = 0;
				color++, dfs(i, j, color, n);
				num[color] = size;				
			}
	int ans = 0;
	forn (i, n - k + 1)
	{
		int zero = 0, sum = 0;
		forn (j, color + 1)
			cnt[j] = 0;
	    forab (x, i - 1, i + k + 1)
	    	forn (y, k + 1) {
				if (!good(x, y, n))
					continue;
				if (x >= i && x < i + k && y < k) {
					handleIn(x, y, sum, zero, 1); 
					continue;
				}
				if (y == k && (x == i - 1 || x == i + k))
					continue;							
				handleIn(x, y, sum, zero, 0); 
		    }
		forn (j, n - k + 1) {
			ans = max(ans, sum + zero);
			forab (x, i, i + k)
				handleOut(x, j, sum, zero, 1);
            if (j != n - k)
				forab (x, i, i + k)
					handleIn(x, j + k, sum, zero, 1);
			if (i != 0) {
				handleOut(i - 1, j, sum, zero, 0);
				if (j != n - k)
					handleIn(i - 1, j + k, sum, zero, 0);
			}
			if (i != n - k) {
				handleOut(i + k, j, sum, zero, 0);
				if (j != n - k)
					handleIn(i + k, j + k, sum, zero, 0);
            }
        	if (j != 0)
        		forab (x, i, i + k)
        			handleOut(x, j - 1, sum, zero, 0);
        	if (j != n - k)
        		forab (x, i, i + k)
        			handleOut(x, j + k, sum, zero, 0);
			forab (x, i, i + k)
        		handleIn(x, j, sum, zero, 0);
		    if (j < n - k - 1)
				forab (x, i, i + k)
	        		handleIn(x, j + k + 1, sum, zero, 0);        
		}
	}
	printf("%d\n", ans);
	return 0;
}