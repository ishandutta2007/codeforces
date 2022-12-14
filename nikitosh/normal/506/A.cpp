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

const int SQ = 300;

int n, d, p, cnt[30005], max1;
pair <bool, int> ans[30005][605];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p);
		cnt[p]++;
	}
	ans[d][SQ] = mp(1, cnt[d]);
	max1 = cnt[d];
	for (int i = d + 1; i <= 30000; i++)
	{
		for (int j = 0; j < 2 * SQ + 1; j++)
		{
			if ((d - SQ + j) <= 0 || (i - (d - SQ + j)) < 0)
				continue;
			int was = 0;
			int cur = 0;
			if (j > 0 && ans[i - (d - SQ + j)][j - 1].first)
			{
			    was = 1;
				cur = max(cur, ans[i - (d - SQ + j)][j - 1].second);
			}
			if (ans[i - (d - SQ + j)][j].first)
			{
			    was = 1;
				cur = max(cur, ans[i - (d - SQ + j)][j].second);
			}
	
			if (ans[i - (d - SQ + j)][j + 1].first)
			{
			    was = 1;
				cur = max(cur, ans[i - (d - SQ + j)][j + 1].second);
			}


			if (was)
			{
				ans[i][j] = mp(1, cur + cnt[i]);
				max1 = max(max1, ans[i][j].second);
			}
		}
	}
	printf("%d\n", max1);
	return 0;
}