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

const int MAXN = 1e6;

int a[MAXN];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, k;
	scanf("%d%d", &n, &k);	
    forn (i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);
	if (k == 0) {
		printf("%d\n", a[n - 1] - a[0]);
		return 0;
	}
	/*int it1 = 0, it2 = n - 1;
	while (k > 0 && it1 < it2 && a[it1] < a[it2]) {
	 	while (it1 < n && a[it1] == a[it1 + 1])
	 		it1++;
	 	while (it2 < n && a[it2] == a[it2 - 1])
	 		it2--;
	 	if (it2 <= it1)
	 		break;
	 	ll d1 = (it1 + 1) * 1ll * (a[it1 + 1] - a[it1]);
	 	ll d2 = (n - it2) * 1ll * (a[it2] - a[it2 - 1]);
	 	if (d1 
	}*/
	int l = 0, r = 1e9 + 1;
	while (r - l > 1) {
	 	int mm = (l + r) / 2;
	 	ll cnt1 = 0, cnt2 = 0;
	 	forn (i, n)
	 		if (a[i] < mm)
	 			cnt1 += mm - a[i];
		fornr (i, n)
			if (a[i] > mm)
				cnt2 += a[i] - mm;
		if (cnt1 <= k && cnt2 >= cnt1)
			l = mm;
		else
			r = mm;
	}
	int lef = l;
	forn (i, n)
		a[i] *= -1;
	l = -1e9 - 1, r = 0;
	while (r - l > 1) {
	 	int mm = (l + r) / 2;
	 	ll cnt1 = 0, cnt2 = 0;
	 	forn (i, n)
	 		if (a[i] < mm)
	 			cnt1 += mm - a[i];
		fornr (i, n)
			if (a[i] > mm)
				cnt2 += a[i] - mm;
		if (cnt1 <= k && cnt2 >= cnt1)
			l = mm;
		else
			r = mm;
	}
	printf("%d\n", -l - lef);
	return 0;
}