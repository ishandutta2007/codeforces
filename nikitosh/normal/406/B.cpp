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

const int s = 1e6;

int n, k, used[1000005], sz;
vector <int> ans;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		used[k] = 1;
	}
	sz = 1;
	for (int i = 1; i <= s; i++)
	{
		if (used[i] == 1)
		{
			if (used[s - i + 1] == 0)
			{
				ans.pb(s - i + 1);
				//used[s - i + 1] = 1;
			}
			else
			{
				if (i > s / 2)
					continue;
				for (int j = sz; j < s; j++)
					if (used[j] == 0 && used[s + 1 - j] == 0)
					{
						//used[j] = 1;
						//used[s - 1 - j] = 1;
						if (j != 0)
							ans.pb(j);
						ans.pb(s + 1 - j);
						sz = j + 1;
						break;
					}
			}
		}
	}
	printf("%d\n", (int) ans.size());
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}