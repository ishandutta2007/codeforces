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

int n;
vector <int> v;
char s[105];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] >= '1' && s[i] <= '3')
			v.pb(s[i] - '0');
	sort(v.begin(), v.end());
	for (int i = 0; i < (int) v.size() - 1; i++)
		printf("%d+", v[i]);
	printf("%d\n", v[(int) v.size() - 1]);
	return 0;
}