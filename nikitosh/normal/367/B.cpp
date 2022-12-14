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

int n, m, p, a[200005], b[200005], l, t, boo, ans[200005], sz;
vector <int> v;
map <int, int> used;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sort(b, b + m);
	for (int g = 0; g < p; g++)
	{
		l = g;
		if (l + (long long) (m - 1) * (long long) p >= n)
		{
			break;
		}
		//printf("l = %d\n", l);
		v.clear();
		for (int i = 0; i < m; i++)
		{
			v.pb(b[i]);
			used[b[i]]++;
		}
		while(l < n)
		{
			v.pb(a[l]);
			l += p;
		}              	
		l = g;
		for (int i = 0; i < m; i++)
		{
			t = l + i * p;
			used[a[t]]--; 
		//	printf("%d ", t);
		}
		//puts("");
		boo = 0;
		for (int i = 0; i < m; i++)
		{
			if (i == 0 || (i != 0 && b[i] != b[i - 1]))
			{
				if (used[b[i]] > 0)
					boo++;
		//		printf("%d %d\n", b[i], used[b[i]]);
			}
		}
		l = t;
		if (boo == 0)
			ans[l] = 1;
		while (l < n)
		{
			l += p;
			if (l >= n)
				break;
			if (a[l] == a[l - (long long) m * (long long) p])
			{
				if (ans[l  - p] == 1)
				{       
					ans[l] = 1;
				}
				continue;
			}
			used[a[l]]--;
			if (used[a[l]] == 0)
				boo--;
			//if (used[a[l]] == -1)
			//	boo++;
			used[a[l - (long long) m * (long long) p]]++;
			//if (used[a[l - (long long) m * (long long) p]] == 0)
			//	boo--;
			if (used[a[l - (long long) m * (long long) p]] == 1)
				boo++;
			
			if (boo == 0)               
				ans[l] = 1;				
		}
		for (int i = 0; i < (int) v.size(); i++)
			used[v[i]] = 0;
	}
	for (int i = 0; i < n; i++)
		if (ans[i])
			sz++;
	printf("%d\n", sz);		
	for (int i = 0; i < n; i++)
		if (ans[i])
			printf("%I64d ", i + 1 - (long long) (m - 1) * (long long) p);
	return 0;
}