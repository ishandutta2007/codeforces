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
int n, m, kk[1000005], ll[1000005], l, r, N, v, t[5000005];
vector <int> c[1000005], close;
map < pair <int, int>, int> ans;

int get (int v, int ll, int rr)
{
 	if (ll > r || rr < l)
 		return 0;
 	if (ll >= l && rr <= r)
 		return t[v];
 	int mm = (ll + rr) / 2;
 	return get(2 * v, ll, mm) + get(2 * v + 1, mm + 1, rr);
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	gets(s);
	n = strlen(s);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &kk[i], &ll[i]);
		kk[i]--;
		ll[i]--;
		c[kk[i]].pb(ll[i]);
	}
	N = 1 << 20;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == ')')
			close.pb(i);
		else
		{
			if (close.size() > 0)
			{
				v = close[(int) close.size() - 1];
				//printf("%d\n", v);
				v += N;
				while (v > 0)
				{
					t[v]++;
					v /= 2;
			   	}
				close.pop_back();
			}
		}
		for (int j = 0; j < (int) c[i].size(); j++)
		{
		    l = i;
			r = c[i][j];
			//printf("%d %d %d\n", i, c[i][j], get(1, 0, N - 1));
			ans[mp(i, c[i][j])] = get(1, 0, N - 1);
		}
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", 2 * ans[mp(kk[i],ll[i])]);
	return 0;
}