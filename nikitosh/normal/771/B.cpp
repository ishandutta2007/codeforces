#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
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

const int MAX_N = 1e5 + 5;

char s[MAX_N];
int a[MAX_N], ans[MAX_N];

void print(int k) {
    forn (i, 26)
    	forn (j, 26)
    		if (i * 26 + j == k) {
    		 	printf("%c%c ", 'A' + i, 'a' + j);
    		}
}	

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, k;
	scanf("%d%d", &n, &k);
	forn (i, n - k + 1) {
	 	scanf("%s", s);
	 	if (s[0] == 'Y')
			a[i] = 1;
		else
			a[i] = 0;	 		
	}
	int sum = 0;
	forn (i, n - k + 1)
		sum += a[i];
	if (sum == 0) {
	 	forn (i, n)
	 		printf("%c ", 'A');
	 	puts("");
	 	return 0;
	}
	int cnt = 0;
	forn (i, n - k + 1)
		if (a[i] == 1) {
		    forab (j, i, i + k)
		    	ans[j] = cnt++;
		 	fornr (j, i)
		 		if (a[j] == 1)
		 			ans[j] = cnt++;
		 		else
		 			ans[j] = ans[j + k - 1];
		 	forab (j, i + 1, n + k - 1)
		 		if (a[j] == 1)
		 			ans[j + k - 1] = cnt++;
		 		else
		 			ans[j + k - 1] = ans[j];
		 	break;
		}
	forn (i, n)
		print(ans[i]);
	puts("");
	return 0;
}