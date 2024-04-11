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

int n, a[100005];
string s[100005], t[100005], last;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> t[i];
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
		if (i == 0)
		{
			if (s[a[i]] < t[a[i]])
				last = s[a[i]];
			else
				last = t[a[i]];
		}
		else
		{
			if (s[a[i]] < t[a[i]])
			{
				if (s[a[i]] > last)
					last = s[a[i]];
				else
				{
					if (t[a[i]] > last)
						last = t[a[i]];
					else
					{
						puts("NO");
						return 0;
					}
				}
			}
			else
			{
 				if (t[a[i]] > last)
					last = t[a[i]];
				else
				{
					if (s[a[i]] > last)
						last = s[a[i]];
					else
					{
						puts("NO");
						return 0;
					}
				}

			}
		}
	}    
	puts("YES");
    return 0;
}