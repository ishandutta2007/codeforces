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

const int INF = 2e9;

int n, a[2005][2005], boo, l, min1, ind, used[2005];
vector <int> v, v2, v3;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < n; j++)
    	{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0 && i != j)
			{
				puts("NO");
				return 0;
			}
		}
		if (a[i][i] != 0)
		{
			puts("NO");
			return 0;
		}
		v.pb(i);
	}	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != a[j][i])
			{
				puts("NO");
				return 0;
			}

	if (n == 1)
	{
		puts("YES");
		return 0;
	}
	while(1)
	{
		for (int i = 0; i < (int) v.size(); i++)
		{
			l = v[i];
			min1 = INF;
			for (int j = 0; j < n; j++)
				if (used[j] == 0 && a[l][j] != 0 && a[l][j] < min1)
				{
					ind = j;
					min1 = a[l][j];
				}	
			boo = 1;
			for (int j = 0; j < n; j++)
			{
				if (l == j)
					continue;
				if (used[j] == 0 && a[ind][j] + min1 != a[l][j])
					boo = 0;
			}
			if (boo == 1)
			{
				//printf("%d\n", l);
				//used[l] = 1;
				v3.pb(l);
				v2.pb(ind);
			}
		}
		//cout << "OK" << endl;
		if (v2.size() == 0)
		{
			puts("NO");
			return 0;
		}
		//printf("%d\n", v2.size());
		for (int i = 0; i < (int) v3.size(); i++)
			used[v3[i]] = 1;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (used[i] == 0)
				cnt++;
		//printf("%d\n", used[0]);
		if (cnt <= 1)
		{
			puts("YES");
			return 0;
		}
		v.clear();
		v3.clear();
		v = v2;
		v2.clear();
		//printf("%d\n", v.size());
	}   
    return 0;
}