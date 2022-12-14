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

char s[200005];
int n, ans, last, len1, len2, l;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	gets(s);
	n = strlen(s);
	if (s[0] < s[1])
		l = 1;
	for (int i = l; i < n; i++)
	{
		if (s[i] == '0' && s[i - 1] != '0')
			last = i;
		if (s[i] == '0' && s[i + 1] != '0')
		{
			len1 = last - 1;
			len2 = i - last + 2;
			if (len1 < len2 || (len1 == len2 && s[0] < s[last - 1]))
				ans = 1;
		}
		if (s[i] != '0')
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}