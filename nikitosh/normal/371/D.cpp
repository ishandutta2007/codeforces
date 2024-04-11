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

int n, m, a[200005], b[200005], t, p, x, k;
set <int> s;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		s.insert(i);
	scanf("%d", &m);
	for (int g = 0; g < m; g++)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d%d", &p, &x);
			p--;
			while(1)
			{
				set<int>::iterator it = s.lower_bound(p);
				if (it == s.end())
					break;
				p = *it;
				if (b[p] + x < a[p])
				{
					b[p] += x;
					break;
				}
				if (b[p] + x == a[p])
				{
					b[p] += x;
					s.erase(p);
					break;
				}
				x -= (a[p] - b[p]);
				b[p] = a[p];
				s.erase(p);
			}
		}
		else
		{
			scanf("%d", &k);
			k--;
			printf("%d\n", b[k]);
		}
	}
	return 0;
}