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

int m, n, t[200005], x[200005], l[200005], c[200005], it;
vector <long long> ans;
long long k, sz;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &t[i]);
		if (t[i] == 1)
		{
			scanf("%d", &x[i]);
			sz++;
			ans.pb(sz);
		}
		else
		{
			scanf("%d%d", &l[i], &c[i]);
			sz += l[i] * c[i];
			ans.pb(sz);
		}
	}
	scanf("%d", &n);
	//for (int i = 0; i < (int) ans.size(); i++)
	//	printf("%d ", ans[i]);
	for (int i = 0; i < n; i++)
	{
		//cerr << i << endl;
		scanf("%I64d", &k);
		while(1)
		{
			it = lower_bound(ans.begin(), ans.end(), k) - ans.begin();
			//printf("it = %d\n", it);
			if (t[it] == 1)
			{
				printf("%d ", x[it]);
				break;
			}
			else
			{
				k = (k - ans[it - 1]) % l[it];
				if (k == 0)
					k += l[it];
			}
		}
	}
	return 0;
}