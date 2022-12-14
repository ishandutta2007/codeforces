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

int n, m, a[1005], b[1005], used[1005], ind, l, Ans;
vector <int> ans;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		b[i]--;
		if (used[b[i]] == 0)
			ans.pb(b[i]);
		used[b[i]] = 1;
	}  
	for (int i = 0; i < n; i++)
		if (used[i] == 0)
			ans.pb(i);
	for (int i = 0; i < m; i++)
	{
		ind = -1;
		for (int j = 0; j < n; j++)
			if (ans[j] == b[i])
			{
				ind = j;
				break;
			}
		for (int j = 0; j < ind; j++)
			Ans += a[ans[j]];
		l = ans[ind];
		for (int j = ind; j > 0; j--)
			ans[j] = ans[j - 1];
		ans[0] = l;
	}
	printf("%d\n", Ans);
    return 0;
}