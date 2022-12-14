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

int n, used[10][10], cnt1[10], cnt2[10], boo, byt, cnt, ans = 100;
pair <int, int> a[1005];
string s;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
    	cin >> s;
    	if (s[0] == 'R')
    		a[i] = mp(0, s[1] - '1');
    	if (s[0] == 'G')
    		a[i] = mp(1, s[1] - '1');
    	if (s[0] == 'B')
    		a[i] = mp(2, s[1] - '1');
    	if (s[0] == 'Y')
    		a[i] = mp(3, s[1] - '1');
    	if (s[0] == 'W')
    		a[i] = mp(4, s[1] - '1');
    }
    for (int i = 0; i < n; i++)
    	used[a[i].first][a[i].second] = 1;
    for (int i = 0; i < 32; i++)
    {
    	for (int j = 0; j < 32; j++)
    	{
    		for (int x = 0; x < 5; x++)
   				cnt1[x] = 0, cnt2[x] = 0; 
   			cnt = 0;
    		for (int x = 0; x < 5; x++)
    			for (int y = 0; y < 5; y++)
    				if (used[x][y] == 1)
    				{
    					if (((i & (1 << x)) == 0) && ((j & (1 << y)) == 0))
    						cnt++;
    					if (((i & (1 << x)) > 0) && ((j & (1 << y)) == 0))
    						cnt1[x]++;
    					if (((i & (1 << x)) == 0) && ((j & (1 << y)) > 0))
    						cnt2[y]++;
    				}
    		boo = 1;
    		for (int g = 0; g < 5; g++)
    			if (cnt1[g] > 1 || cnt2[g] > 1)
    				boo = 0;	
    		if (cnt > 1)
    			boo = 0;
    		if (boo)
    		{
    			byt = 0;
    			for (int g = 0; g < 5; g++)
    				if (i & (1 << g))
    					byt++;
    			for (int g = 0; g < 5; g++)
    				if (j & (1 << g))
    					byt++;
    			ans = min(ans, byt);
    			/*printf("%d %d %d %d\n", i, j, ans, byt);
    			printf("%d\n", cnt);
    			for (int g = 0; g < 5; g++)
    				printf("%d ", cnt1[g]);
    			puts("");
    			for (int g = 0; g < 5; g++)
    				printf("%d ", cnt2[g]);
    			puts(""); */
    		}
    	}	
    }
    printf("%d\n", ans);
    return 0;
}