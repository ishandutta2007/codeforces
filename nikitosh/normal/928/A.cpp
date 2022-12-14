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

const int MAX_N = 1e3 + 5;

char str[MAX_N], t[MAX_N];

void normalize(char *s) {
    int len = strlen(s);
    forn (i, len) {
     	if (s[i] == '0')
     		s[i] = 'O';
     	if (s[i] == '1' || s[i] == 'i' || s[i] == 'I')
     		s[i] = 'l';
    	if (s[i] >= 'A' && s[i] <= 'Z')
    		s[i] += 'a' - 'A';
    }    
}	

bool check(char *s, char *t) {
 	int len1 = strlen(s), len2 = strlen(t);
 	if (len1 != len2)
 		return 0;
 	forn (i, len1)
 		if (s[i] != t[i])
 			return 0;
	return 1;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	gets(str);
	normalize(str);
	int n;
	scanf("%d\n", &n);
	forn (i, n) {
		gets(t);
		normalize(t);
		if (check(str, t)) {
		 	puts("No");
		 	return 0;
		}
	}	
	puts("Yes");
	return 0;
}