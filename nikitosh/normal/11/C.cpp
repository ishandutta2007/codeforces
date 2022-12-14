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

const int MAX_N = 550;

int n, m;
int a[MAX_N][MAX_N];
char s[MAX_N];       

bool isGood(int i, int j) {
 	return i >= 0 && j >= 0 && i < n && j < m;
}

bool check(int i, int j, int len, pii turn, int need) {
    int cnt = 0;
	forn (k, len) {
		if (isGood(i, j))
			cnt += a[i][j];
		i += turn.fs, j += turn.sc;
	}
	return cnt == need * len;
}


int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int t;
	scanf("%d", &t);
	forn (tt, t) {
	    scanf("%d%d\n", &n, &m);
	    forn (i, n) {
	     	gets(s);
	     	forn (j, m)
	     		a[i][j] = s[j] - '0';
	    }
	    int ans = 0;
	    forn (i, n)
			forn (j, m)
				if (a[i][j] == 1) {
					int g = j;
					while (g < m && a[i][g])
						g++;
					int l = g - j;
					//printf("%d %d %d l = %d\n", i, j, g, l);
					if (l >= 2 && check(i, j, l, {1, 0}, 1) && check(i, j, l, {0, 1}, 1) && check(i, j + l - 1, l, {1, 0}, 1) && check(i + l - 1, j, l, {0, 1}, 1)
					           && check(i + 1, j + 1, l - 2, {1, 0}, 0) && check(i + 1, j + 1, l - 2, {0, 1}, 0) && check(i + 1, j + l - 2, l - 2, {1, 0}, 0) && check(i + l - 2, j + 1, l - 2, {0, 1}, 0) 
					           && check(i - 1, j - 1, l + 2, {1, 0}, 0) && check(i - 1, j - 1, l + 2, {0, 1}, 0) && check(i - 1, j + l, l + 2, {1, 0}, 0) && check(i + l, j - 1, l + 2, {0, 1}, 0)) 
						ans++;
					//printf("ANS = %d\n", ans);
					j = g - 1;
		     	}	
		forn (d, n + m - 1)
			fornr (i, min(n, d + 1))
				if (d - i < m && a[i][d - i] == 1) {
					int g = i;
					while (g >= 0 && a[g][d - g])
						g--;
					int l = i - g;
					int j = d - i;
					//printf("%d %d %d l = %d\n", i, j, g, l);
					//printf("%d %d %d %d\n", getDiag1(d, j, j + l), getDiag2(i - j + m, j, j + l), getDiag1(d + 2 * (l - 1), j + l - 1, j + 2 * l - 1), getDiag2(i - j + m - 2 * (l - 1), j + l - 1, j + 2 * l - 1));
					if (l >= 2 && check(i, j, l, {-1, 1}, 1) && check(i, j, l, {1, 1}, 1) && check(i, j + 2 * (l - 1), l, {-1, -1}, 1) && check(i, j + 2 * (l - 1), l, {1, -1}, 1)
					           && check(i, j + 1, l - 1, {-1, 1}, 0) && check(i, j + 1, l - 1, {1, 1}, 0) && check(i, j + 2 * l - 3, l - 1, {-1, -1}, 0) && check(i, j + 2 * l - 3, l - 1, {1, -1}, 0)
					           && check(i, j - 1, l + 1, {-1, 1}, 0) && check(i, j - 1, l + 1, {1, 1}, 0) && check(i, j + 2 * l - 1, l + 1, {-1, -1}, 0) && check(i, j + 2 * l - 1, l + 1, {1, -1}, 0)
         					   && check(i - 1, j - 1, l, {-1, 1}, 0) && check(i + 1, j - 1, l, {1, 1}, 0) && check(i - 1, j + 2 * (l - 1) + 1, l, {-1, -1}, 0) && check(i + 1, j + 2 * (l - 1) + 1, l, {1, -1}, 0)
					           && check(i, j + 2, l - 2, {-1, 1}, 0) && check(i, j + 2, l - 2, {1, 1}, 0) && check(i, j + 2 * l - 4, l - 2, {-1, -1}, 0) && check(i, j + 2 * l - 4, l - 2, {1, -1}, 0))
						ans++;
					//printf("ANS = %d\n", ans);
					i = g + 1;
		     	}	
		printf("%d\n", ans);		
	}	

	return 0;
}