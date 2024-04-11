#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

char s[15];
int sz, a[15], m, d[1005][15][15];
vector <int> v;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	gets(s);
	scanf("%d", &m);
	for (int i = 0; i < 10; i++)
	{
		if (s[i] == '1')
			a[sz++] = i + 1;
	}
  	for (int i = 0; i < sz; i++)
  		d[1][a[i]][a[i]] = 1;
   	for (int i = 2; i <= m; i++)
   	{
   	 	for (int j = 1; j <= 10; j++)
   	 		for (int g = 0; g < sz; g++)
				if (a[g] > j)
					for (int l = 0; l < sz; l++)
						if (l != g && d[i - 1][a[g] - j][a[l]] == 1)
						{
							d[i][j][a[g]] = 1;
   	 						break;
   	 					}	
   	}
   	int boo = 0;
   	int i1 = m, j1 = 0, g1 = 0;
   	for (int i = 1; i <= 10; i++)
   		for (int j = 0; j < sz; j++)
   			if (d[m][i][a[j]] == 1)
   			{
   				boo = 1;
  				j1 = i;
  				g1 = a[j];
  			}
  	if (boo == 0)
  	{
  		puts("NO");
  		return 0;
  	}
  	puts("YES");
  	for (int i = 0; i < m; i++)
  	{
  		i1--;
  		v.pb(g1);
  		j1 = g1 - j1;
  		for (int j = 0; j < sz; j++)
  			if (d[i1][j1][a[j]] == 1 && a[j] != g1)
  			{
  				g1 = a[j];
  				break;
  			}
  	}
  	for (int i = (int) v.size() - 1; i >= 0; i--)
  		printf("%d ", v[i]);
  	return 0;
}