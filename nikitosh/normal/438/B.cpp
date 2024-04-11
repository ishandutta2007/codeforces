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

int n, m, a[100005], k, l, par[100005], sz[100005], it, used[100005];
pair <int, int> b[100005];
vector <int> c[100005];
long long ans = 0;
vector < pair <int, int> > tmp;

int get (int v)
{
	if (v == par[v])
		return v;
	return par[v] = get(par[v]);
}

void Union (int a, int b)
{
 	a = get(a);
	b = get(b);
	if (a != b) 
	{
		if (sz[a] < sz[b])
			swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
	}
} 

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = mp(a[i], i);
	}
	sort(b, b + n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &k, &l);
		k--;
		l--;
		c[k].pb(l);
		c[l].pb(k);
	}
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		it = b[i].second;
		used[it] = 1;
		long long sum = 0, ans_tmp = 0;
		tmp.clear();
		for (int j = 0; j < (int) c[it].size(); j++)
			if (used[c[it][j]] == 1)
			{
				tmp.pb(mp(get(c[it][j]), sz[get(c[it][j])]));
			}	
		sort(tmp.begin(), tmp.end());
		for (int j = 0; j < (int) tmp.size(); j++)
		{
			if (j != 0 && tmp[j].first == tmp[j - 1].first)
				continue;
			ans_tmp += sum * tmp[j].second;
			sum += tmp[j].second; 
		}
		for (int j = 0; j < (int) c[it].size(); j++)
			if (used[c[it][j]] == 1)
		    	Union(it, c[it][j]);
		ans_tmp += sum;
		ans += ans_tmp * b[i].first;
	}
	printf("%.20lf\n", 2 * ans / (double) ((long long) n * (n - 1)));
	return 0;
}