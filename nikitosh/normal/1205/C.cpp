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
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 105;

int n;
int a[MAX_N][MAX_N];

int ask(int sX, int sY, int tX, int tY) {
 	printf("? %d %d %d %d\n", sX + 1, sY + 1, tX + 1, tY + 1);
 	fflush(stdout);
 	int k;
 	scanf("%d", &k);
 	return k;
}

void invert() {
 	forn (i, n)
 		forn (j, n)
 			if ((i + j) % 2 == 1)
 				a[i][j] ^= 1;
}

void print() {
 	printf("!\n");
 	forn (i, n) {
 		forn (j, n) 
 			printf("%d", a[i][j]);
 		puts("");
 	}
 	fflush(stdout); 	
}

int main() {


	scanf("%d", &n);
	a[0][0] = 1;
	a[n - 1][n - 1] = 0;
	for (int i = 0; i < n - 1; i++) {
		int k = 0;
		if (i + 2 < n) {
	 		k = ask(0, i, 0, i + 2);
		 	if (k)
		 		a[0][i + 2] = a[0][i];
	 		else
	 			a[0][i + 2] = a[0][i] ^ 1;
	 	}
	 	k = ask(0, i, 1, i + 1);
	 	if (k)
	 		a[1][i + 1] = a[0][i];
	 	else
	 		a[1][i + 1] = a[0][i] ^ 1;	
	}
	int k = ask(1, 0, 1, 2);
	if (k)
		a[1][0] = a[1][2];
	else
		a[1][0] = a[1][2] ^ 1;	
	forn (i, n) {
	 	forn (j, n - 2) {
		 	k = ask(j, i, j + 2, i);
		 	if (k)
	 			a[j + 2][i] = a[j][i];
	 		else
	 			a[j + 2][i] = a[j][i] ^ 1;
	 	}
	}
	forn (i, n - 2)
		if (a[i][i] == 1 && a[i + 1][i + 1] == 1 && a[i + 2][i + 2] == 0) {
			k = ask(i, i, i + 2, i + 1);
			if (k) {
			 	if (a[i + 2][i + 1] != a[i][i])
			 		invert();
			 	print();
			 	return 0;
		 	}
		 	int l = ask(i + 1, i, i + 2, i + 2);
		 	if (l) {
		 	 	if (a[i + 1][i] != a[i + 2][i + 2])
			 		invert();
			 	print();
			 	return 0;		 	
		 	}
		 	if (a[i + 2][i + 1] != 0)
		 		invert();
		 	print();
		 	return 0;	
		}
	forn (i, n - 2)
		if (a[i][i] == 1 && a[i + 1][i + 1] == 0 && a[i + 2][i + 2] == 0) {
			k = ask(i, i, i + 2, i + 1);
			if (k) {
			 	if (a[i + 2][i + 1] != a[i][i])
			 		invert();
			 	print();
			 	return 0;
		 	}
		 	int l = ask(i + 1, i, i + 2, i + 2);
		 	if (l) {
		 	 	if (a[i + 1][i] != a[i + 2][i + 2])
			 		invert();
			 	print();
			 	return 0;		 	
		 	}
		 	if (a[i + 1][i] != 1)
		 		invert();
		 	print();
		 	return 0;	
		}
	print();
	return 0;
}