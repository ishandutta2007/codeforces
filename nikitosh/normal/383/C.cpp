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

const int maxn = 400005;

int n, m, a[maxn], used[maxn], h[maxn], pos1[maxn], pos2[maxn], k, l, N, type[maxn], x[maxn], 
val[maxn], t[6000005], r, height = 0;
vector <int> c[maxn], go; 

void sum (int v, int ll, int rr, int p)
{
	if (ll >= l && rr <= r)
	{
		t[v] += p;
		return;
	}
	if (ll > r || rr < l)
		return;
	int mm = (ll + rr) / 2;
	sum(2 * v, ll, mm, p);
	sum(2 * v + 1, mm + 1, rr, p);
} 

void dfs (int v)
{
	used[v] = 1;
	h[v] = height++;
	go.pb(v);
	pos1[v] = (int) go.size() - 1;
	for (int i = 0; i < (int) c[v].size(); i++)
		if (used[c[v][i]] == 0)
			dfs(c[v][i]);
	go.pb(v);
	pos2[v] = (int) go.size() - 1;
	height--;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &k, &l);
		c[k].pb(l);
		c[l].pb(k);
	}
	dfs(1);
	N = 1 << 20;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &type[i]);
		if (type[i] == 1)
		{
			scanf("%d%d", &x[i], &val[i]);
			l = pos1[x[i]];
			r = pos2[x[i]];
			if (h[x[i]] % 2 == 0)
				sum(1, 0, N - 1, val[i]);
			else
				sum(1, 0, N - 1, -val[i]);
		}
		else
		{
			scanf("%d", &x[i]);
    		int s = N + pos1[x[i]];
    		int sum = 0;
    		while (s > 0)
    		{
    			sum += t[s];
				s /= 2;    				
    		}
    		if (h[x[i]] % 2 == 1)
    			sum *= (-1);
    		sum += a[x[i] - 1];
    		printf("%d\n", sum);
    	}
    }	
    return 0;
}