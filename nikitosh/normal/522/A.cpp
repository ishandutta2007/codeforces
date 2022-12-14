#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#define FNAME "1"

int n, max1;
map <string, int> d;
string s, t, r;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	d["polycarp"] = 1;
	scanf("%d\n", &n);
	max1 = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t >> r;
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		std::transform(r.begin(), r.end(), r.begin(), ::tolower);
		d[s] = d[r] + 1;
		max1 = max(max1, d[s]);
   	} 
   	printf("%d\n", max1);
    return 0;
}