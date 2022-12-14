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

#define FNAME "1"
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

int tmp, n, sz, t, boo, l;
vector <int> v[12], ans, AN[10];
long long p;
char s[20];
pair <int, int> ob[100];

int foo (long long a)
{
	if (a < 0)
		return 0;
	//printf("a = %I64d\n", a);
    if (a == 0 || a == 7 || a == 4 || a == 8)
	{
		if (a != 0)
		    ans.pb(a);
		return 1;
	}
	if (a < 10)
		return 0;
	int q = a % 10;
	for (int i = 0; i < (int) v[q].size(); i++)
		if (foo((a - v[q][i]) / 10) == 1)
		{
			ans.pb(v[q][i]);
			return 1;
		}
	return 0;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	for (int i = 0; i <= 6; i++)
		for (int j = 0; j <= 6 - i; j++)
		{
			tmp = 7 * i + 4 * j;
			v[tmp % 10].pb(tmp);
			ob[tmp] = mp(i, j);
		}
	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < (int) v[i].size(); j++)
			printf("%d ", v[i][j]);
		puts("");
	}*/
	scanf("%d", &t);
	for (int g = 0; g < t; g++)
	{
		scanf("%I64d", &p);
		for (int i = 0; i < 6; i++)
			AN[i].clear();
		ans.clear();
		boo = foo(p);
		if (boo == 0)
		{
			puts("-1");
			continue;
		}
        for (int j = 0; j < (int) ans.size(); j++)
		{
		    //printf("%d\n", ans[j]);
			//printf("ololo = %d %d\n", ob[ans[j]].first, ob[ans[j]].second);
			for (int i = 0; i < ob[ans[j]].first; i++)
				AN[i].pb(7);
			for (int i = 0; i < ob[ans[j]].second; i++)
				AN[i + ob[ans[j]].first].pb(4);
			for (int i = 0; i < 6 - ob[ans[j]].first - ob[ans[j]].second; i++)
				AN[i + ob[ans[j]].first + ob[ans[j]].second].pb(0);
		}
		for (int i = 0; i < 6; i++)
		{
			//reverse(AN[i].begin(), AN[i].end());	
			l = (int) AN[i].size() - 1;
			for (int j = 0; j < (int) AN[i].size(); j++)
				if (AN[i][j] != 0)
				{
					l = j;
					break;
				}
			for (int j = l; j < (int) AN[i].size(); j++)
				printf("%d", AN[i][j]);
			printf(" ");
		}
		puts("");
	}
	return 0;
}