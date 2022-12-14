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

const int MAX_N = 2e5;

int x[MAX_N], y[MAX_N];
set<pair<double, int>> s1, s2;

ll sqr(ll a) {
 	return a * a;
}

ld dist(int x_1, int y_1, int x_2, int y_2) {
	return sqrt(sqr(x_1 - x_2) + sqr(y_1 - y_2));
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int x_1, y_1, x_2, y_2, x_0, y_0, n;
	scanf("%d%d%d%d%d%d", &x_1, &y_1, &x_2, &y_2, &x_0, &y_0);
	scanf("%d", &n);
	double ans = 0;
	forn (i, n) {
		scanf("%d%d", &x[i], &y[i]);
		ld d = dist(x[i], y[i], x_0, y_0);
		ans += 2 * d;
		s1.insert(mp(dist(x[i], y[i], x_1, y_1) - d, i));
		s2.insert(mp(dist(x[i], y[i], x_2, y_2) - d, i));
	}
	double minn = ans + s1.begin()->fs;
	minn = min(minn, ans + s2.begin()->fs);
	if (s1.begin()->sc == s2.begin()->sc) {
		if (n == 1) {
			printf("%.20f\n", minn);
			return 0;
		}
		auto it1 = s1.begin(), it2 = s2.begin();
		auto it3 = it1, it4 = it2;
		it3++, it4++;
		printf("%.20f\n", min(minn, (double) ans + min(it1->fs + it4->fs, it3->fs + it2->fs))); 
	}
	else {
		printf("%.20f\n", min(minn, (double) ans + s1.begin()->fs + s2.begin()->fs)); 
	}
	return 0;
}