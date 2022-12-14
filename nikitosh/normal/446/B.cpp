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

int n, m, k, p, a[1005][1005], str, stl, tmp;
multiset <int> s1, s2;
long long Ans = -1e18, ans1[1000005], ans2[1000005];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
	{
		str = 0;
		for (int j = 0; j < m; j++)    
    		str += a[i][j];
    	s1.insert(str);
    }
    for (int i = 0; i < m; i++)
	{
		stl = 0;
		for (int j = 0; j < n; j++)    
    		stl += a[j][i];
    	s2.insert(stl);
    }
    multiset<int>::iterator it1, it2;
    for (int i = 1; i <= k; i++)
    {
		it1 = s1.end();
		it1--;    	
		tmp = *it1;
		s1.erase(it1);
		ans1[i] = ans1[i - 1] + tmp;
    	s1.insert(tmp - m * p);	
	}
    for (int i = 1; i <= k; i++)
    {
		it2 = s2.end();
		it2--;    	
		tmp = *it2;
		s2.erase(it2);
		ans2[i] = ans2[i - 1] + tmp;
		s2.insert(tmp - n * p);	
	}
    for (int i = 0; i <= k; i++)
    	Ans = max(Ans, ans1[i] + ans2[k - i] - (long long) i * (k - i) * p);
    printf("%I64d\n", Ans);
    return 0;
}