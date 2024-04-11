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

char s[1000005];
int p[1000005], l, n, j;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	gets(s);
	n = strlen(s);
	for (int i = 1; i < n; i++)
	{
		j = p[i - 1];
		while(j > 0 && s[j] != s[i])
			j = p[j - 1];
		if (s[i] == s[j])
			j++;
		p[i] = j;
	}
	l = p[n - 1];
	if (l != 0)
		for (int i = 1; i < n - 1; i++)
			if (p[i] == l)
			{
				for (int j = 0; j < l; j++)
					printf("%c", s[j]);
				return 0;
			}
	l = p[l - 1];
	if (l != 0)
	{
		for (int j = 0; j < l; j++)
			printf("%c", s[j]);
		return 0;
	}
	puts("Just a legend");	
	return 0;
}