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

int n, m, q, k, l, color, col[600005], used[600005], h, max1, v_ans, v_ans2, pr[600005], par[600005], sz[600005], ans[600005], dim[600005], rad[600005], l1, l2, l3, t, x, y;
vector <int> c[300005], tmp;

void dfs (int v)
{
	col[v] = color;
	tmp.pb(v);
	used[v] = 1;
	if (h > max1)
	{
		max1 = h;
		v_ans = v;
	}
	h++;
	for (int i = 0; i < (int) c[v].size(); i++)
	{
		if (used[c[v][i]] == 0)
			dfs(c[v][i]);
	}
	h--;
}

void dfs2 (int v)
{
	used[v] = 1;
	if (h > max1)
	{
		max1 = h;
		v_ans2 = v;
	}
	h++;
	for (int i = 0; i < (int) c[v].size(); i++)
	{
		if (used[c[v][i]] == 0)
		{
		    pr[c[v][i]] = v;
			dfs(c[v][i]);
		}
	}
	h--;
}

int get (int v)
{
	if (v == par[v])
		return v;
	return par[v] = get(par[v]);
}
   
void Union (int v, int u)
{
	v = get(v);
	u = get(u);
	if (v != u)
	{
	 	if (sz[v] < sz[u])
	 		swap(v, u);
	 	par[u] = v;
	 	sz[v] += sz[u];	
	}
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
   	{
   		par[i] = i;
   		sz[i] = 1;
   	}
   	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &k, &l);
		k--;
		l--;
		c[k].pb(l);
		c[l].pb(k);			
   		Union(k, l);
   	} 
   	for (int i = 0; i < n; i++)
   	{
   		if (used[i] == 0)
   		{
   			tmp.clear();
   			max1 = -1;
   			h = 0;
   			dfs(i);
   			for (int j = 0; j < (int) tmp.size(); j++)
   				used[tmp[j]] = 0;
   			max1 = -1;
   			h = 0;
   			pr[v_ans] = -1;
            dfs2(v_ans);
            dim[color] = max1;
            rad[color] = (max1 + 1) / 2;
            for (int j = 0; j < rad[color]; j++)
            	v_ans2 = pr[v_ans2];
            ans[color] = v_ans2;
   		    color++;
   		}
   	}
   	for (int i = 0; i < q; i++)
   	{
   		scanf("%d", &t);
   		if (t == 1)
   		{
   			scanf("%d", &x);
   			x--;
   			x = get(x);
   			printf("%d\n", dim[col[x]]);
   		}
   		if (t == 2)
   		{
   			scanf("%d%d", &x, &y);
   			x--;
   			y--;
   			//Union(x, y);
   			x = get(x);
   			y = get(y);
   			if (x == y)
   				continue;
   			l1 = dim[col[x]];
   			l2 = dim[col[y]];
   			l3 = rad[col[x]] + rad[col[y]] + 1;
   			dim[color] = max(l1, max(l2, l3));
   			rad[color] = (dim[color] + 1) / 2;
   			if (l1 >= l2 && l1 >= l3)
   				ans[color] = ans[col[x]];		
   			else
   			{
   				if (l2 >= l3)
   					ans[color] = ans[col[y]];
   				else
   				{
   					if (rad[col[x]] <= rad[col[y]])
   						ans[color] = ans[col[y]];
   					else
   						ans[color] = ans[col[x]];
   				}
   			}
   		 	if (sz[x] < sz[y])
	 			swap(x, y);
	 		par[y] = x;
		 	sz[x] += sz[y];	
	        col[x] = color++;
   		}
   	}
   	return 0;
}