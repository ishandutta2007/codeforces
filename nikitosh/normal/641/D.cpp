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
typedef double dbl;

#define FNAME "test"

const int MAX_N = 2e5 + 5;
const long double EPS = 1e-3;

double minn[MAX_N], maxx[MAX_N];
long double p1[MAX_N], p2[MAX_N], s1[MAX_N], s2[MAX_N];

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	scanf("%d", &n);	
	forn (i, n)
		scanf("%lf", &maxx[i]);
	forn (i, n)
		scanf("%lf", &minn[i]);
	forn (i, n)
	{
		long double m = minn[i] + maxx[i];
		long double a = 1;
		long double b = s1[i] - s2[i] - m;
		long double c = maxx[i] - m * s1[i];
		long double d = b * b - 4 * a * c;
        long double l;

        l = (-b - sqrtl(max(d,(LD)0.0))) / (2 * a);
  //              printf("d=%.8f\n",(double)d);
//        printf("%.8f\n",(double)l);
        if (l >= -EPS && l + s1[i] <= 1 + EPS &&  m - l >= -EPS && s2[i] + m - l <= 1 + EPS)
        	p1[i] = l;
        else{
        
        l = (-b + sqrtl(max(d,(LD)0.0))) / (2 * a);
//        printf("%.8f\n",(double)l);
//        if (l >= -EPS && l + s1[i] <= 1 + EPS &&  m - l >= -EPS && s2[i] + m - l <= 1 + EPS)
        	p1[i] = l;        
        	}
        

		p2[i] = m - p1[i];
		s1[i + 1] = s1[i] + p1[i];
		s2[i + 1] = s2[i] + p2[i];
	}

	LD s;
	s=0;
	forn (i, n){
		printf("%.20f ", (dbl)p1[i]);
//		assert(p1[i]>=0);
		s+=p1[i];
	}
	puts("");
//	printf("%.20f\n",(double)s);
//	assert(abs(s-1)<1e-6);
	s=0;
	forn (i, n){
		printf("%.20f ", (dbl)p2[i]);
//		assert(p2[i]>=0);
		s+=p2[i];
	}
	puts("");
//	printf("%.20f\n",(double)s);
//	assert(abs(s-1)<1e-6);
	return 0;
}