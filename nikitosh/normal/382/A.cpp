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

int n, m, l, k1, k2, len;
char s[1005], t[1005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	gets(s);
	gets(t);
	m = strlen(t);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] == '|')
			l = i;
	k1 = l;
	k2 = n - l - 1;
	if (k1 + m < k2 || k2 + m < k1 || (k1 + k2 + m) % 2 == 1)
	{
		puts("Impossible");
		return 0;
	}
	len = (k1 + k2 + m) / 2;
	for (int i = 0; i < l; i++)
		printf("%c", s[i]);
	for (int i = 0; i < len - k1; i++)
		printf("%c", t[i]);
	printf("|");
	for (int i = l + 1; i < n; i++)
		printf("%c", s[i]);
	for (int i = 0; i < len - k2; i++)
		printf("%c", t[len - k1 + i]);
	return 0;
}