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

const int MAX_N = 1e4;

int ans[2][MAX_N], a[2][MAX_N], lose[2][MAX_N];

int n, k[2];

struct S {
  	int num, player, win;
  	S() {}
  	S(int num, int player, int win): num(num), player(player), win(win) {}
};

S q[MAX_N * 4];

inline int sub(int a, int b, int n) {
	a -= b;
	if (a < 0)
		a += n;
  	return a;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

    scanf("%d", &n);
    scanf("%d", &k[0]);
    forn (i, k[0])
    	scanf("%d", &a[0][i]);
    scanf("%d", &k[1]);
    forn (i, k[1])
    	scanf("%d", &a[1][i]);
    int head = 0, tail = 0;
    //num, player, win
    q[tail++] = S(0, 0, 0);
    q[tail++] = S(0, 1, 0);
    forn (i, 2)
    	forn (j, n)
    		ans[i][j] = -1;
	ans[0][0] = 0, ans[1][0] = 0;
    while (tail > head) {
	 	S np = q[head++];
	 	int op = np.player ^ 1;
	 	if (np.win == 0) {
	 	 	forn (j, k[op]) {
		 	 	int num2 = sub(np.num, a[op][j], n);
	 	 		if (ans[op][num2] == -1) {
					ans[op][num2] = 1;
					q[tail++] = S(num2, op, 1);
	 	 		}
	 		}
	 	} else {
	 	 	forn (j, k[op]) {
	 	 		int num2 = sub(np.num, a[op][j], n);
	 	 		lose[op][num2]++;
	 	 		if (lose[op][num2] == k[op]) {
					ans[op][num2] = 0;
					q[tail++] = S(num2, op, 0);
	 	 		}
			}				 	 			 		
	 	}
    }	
    forn (i, 2) {
    	forab (j, 1, n) {
    		if (ans[i][j] == 1)
    			printf("Win ");
    		if (ans[i][j] == 0)
    			printf("Lose ");
    		if (ans[i][j] == -1)
    			printf("Loop ");
       	}
    	puts("");
    }
	return 0;
}