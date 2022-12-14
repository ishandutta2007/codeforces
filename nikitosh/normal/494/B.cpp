#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
 
using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif
 
#define FNAME "1"

const int mod = 1e9 + 7;
char s[100005], t[100005], rr[200005];
int n, m, len, cur, cnt[100005];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 

    gets(s);
    gets(t);
    n = strlen(s);
    m = strlen(t);
    for (int i = 0; i < m; i++)
    	rr[i] = t[i];
    rr[m] = '$';
    for (int i = 0; i < n; i++)
    	rr[m + i + 1] = s[i];
	len = n + m + 1;
	vector <int> z (len);
	for (int i=1, l=0, r=0; i<len; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < len && rr[z[i]] == rr[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	int sum = 1;
	for (int i = 0; i < n - m + 1; i++)
	{
		if (i > 0)
			sum = (sum + cnt[i - 1]) % mod;
		cur = (cur + sum) % mod;
		int d;
		if (i + m - 2 < 0)
			d = 0;
		else
			d = cnt[i + m - 2];
		if (z[m + i + 1] == m)
		{
			cnt[i + m - 1] = (cur) % mod;	 
		}
		else
			cnt[i + m - 1] = d;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + cnt[i]) % mod;
	printf("%d\n", ans);
	return 0;
}