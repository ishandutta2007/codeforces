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

int n, len;
vector <int> v;
string s[100005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> s[i];		
	len = s[0].length();
	for (int i = 0; i < len; i++)
	{
		v.clear();
		for (int j = 0; j < n; j++)
		{
			if (s[j][i] >= 'a' && s[j][i] <= 'z')
				v.pb(s[j][i] - 'a');
		}
		sort(v.begin(), v.end());
		if (v.size() == 0)
			printf("a");
		else
		{
			if (v[0] == v[(int) v.size() - 1])
				printf("%c", 'a' + v[0]);
			else
				printf("?");
		}
	}
	return 0;
}