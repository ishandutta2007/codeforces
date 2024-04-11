#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
 
using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif
 
#define FNAME "1"

int n, m, k, color[105], s, t, c[105][105], f[105][105], kk[105], ll[105], used[105], ans;
vector <int> pr[105], g[105];
map <pair <int, int>, int > cnt;
map <int, bool> was;


void dfs (int v, int col)
{
	used[v] = 1;
	color[v] = col;
	for (int i = 0; i < (int) g[v].size(); i++)
		if (used[g[v][i]] == 0)
			dfs(g[v][i], col ^ 1);
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		for (int j = 2; j * j <= k; j++)
			while (k % j == 0)
			{
				pr[i].push_back(j);
				if (cnt.count(mp(i, j)) == 0)
                	cnt[mp(i, j)] = 1;
                else
                	cnt[mp(i, j)]++;
				k /= j;
			}
   		if (k != 1)
   		{
   			pr[i].pb(k);
   			if (cnt.count(mp(i, k)) == 0)
               	cnt[mp(i, k)] = 1;
            else
              	cnt[mp(i, k)]++;
   		}
   	} 
   	for (int i = 0; i < m; i++)
   	{
   		scanf("%d%d", &kk[i], &ll[i]);
   		kk[i]--;
   		ll[i]--;
   		g[kk[i]].pb(ll[i]);
   		g[ll[i]].pb(kk[i]);
   	}
   	for (int i = 0; i < n; i++)
   		if (used[i] == 0)
   			dfs(i, 0);
   	s = n;
   	t = n + 1;
   	for (int q = 0; q < n; q++)
	{
		for (int g = 0; g < (int) pr[q].size(); g++)
			if (was[pr[q][g]] == 0)
			{
				int P = pr[q][g];
				was[P] = 1;
				for (int i = 0; i < m; i++)
					if (color[kk[i]] == 0)
						c[kk[i]][ll[i]] = 1e9;
					else
						c[ll[i]][kk[i]] = 1e9;
				for (int i = 0; i < n; i++)
				{
					if (color[i] == 0)
						c[s][i] = cnt[mp(i, P)];
					else
						c[i][t] = cnt[mp(i, P)];
				}
				n += 2;
				vector<int> e (n);
				vector<int> h (n);
	h[s] = n-1;
	vector < vector<int> > f (n, vector<int> (n));

	for (int i=0; i<n; ++i) {
		f[s][i] = c[s][i];
		f[i][s] = -f[s][i];
		e[i] = c[s][i];
	}

	vector<int> maxh (n);
	int sz = 0;
	for (;;) {
		if (!sz)
			for (int i=0; i<n; ++i)
				if (i != s && i != t && e[i] > 0) {
					if (sz && h[i] > h[maxh[0]])
						sz = 0;
					if (!sz || h[i] == h[maxh[0]])
						maxh[sz++] = i;
				}
		if (!sz)  break;
		while (sz) {
			int i = maxh[sz-1];
			bool pushed = false;
			for (int j=0; j<n && e[i]; ++j)
				if (c[i][j]-f[i][j] > 0 && h[i] == h[j]+1) {
					pushed = true;
					int addf = min (c[i][j]-f[i][j], e[i]);
					f[i][j] += addf,  f[j][i] -= addf;
					e[i] -= addf,  e[j] += addf;
					if (e[i] == 0)  --sz;
				}
			if (!pushed) {
				h[i] = 2e9;
				for (int j=0; j<n; ++j)
					if (c[i][j]-f[i][j] > 0 && h[j]+1 < h[i])
						h[i] = h[j]+1;
				if (h[i] > h[maxh[0]]) {
					sz = 0;
					break;
				}
			}
		}
	}
			n -= 2;
	        for (int i = 0; i < n; i++)
	        	if (color[i] == 1)
	        		ans += f[i][t];
		}
	}
	printf("%d\n", ans);
    return 0;
}