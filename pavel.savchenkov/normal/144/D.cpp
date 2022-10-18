//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#define pb push_back
#define i64 long long
const double eps = 1e-9;
const int inf = 2000000000;
const double pi = acos(-1.0);
using namespace std;
set < pair < int,int > > q;
int n,m;
vector < pair < int,int > > g[1000000];
int l; int s;
int d[1000000];
int sz;

void add(int u,int v,int c)
{
	   //cout << u << " " << v << " " << c << endl;
	   g[u].pb(make_pair(v,c));
	   g[v].pb(make_pair(u,c));
};

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   scanf("%d%d%d",&n,&m,&s);
   sz = n+1;
   for (int i=1;i<=m;i++)
   {
	   d[i] = inf;
	   int u,v,c;
	   scanf("%d%d%d",&u,&v,&c);
	   g[u].pb(make_pair(v,c));
	   g[v].pb(make_pair(u,c));
   }
   scanf("%d",&l);
   d[s] = 0;
   q.insert(make_pair(d[s],s));
   
   while (!q.empty())
   {
	   
	   int v = q.begin()->second;
	   q.erase(q.begin());
	   for (int i=0; i<(int)g[v].size(); i++)
	   {
		   int to = g[v][i].first;
		   int w = g[v][i].second;
		   if (d[v] + w < d[to])
		   {
			   q.erase(make_pair(d[to],to));
			   d[to] = d[v] + w;
			   q.insert(make_pair(d[to],to));
		   }
	    }
   }
   //for (int i=1;i<=n;i++) cout << d[i] << " "; cout << endl;
   
   int res = 0;
   for (int i=1; i<=n; i++)
	   for (int j=0; j<(int)g[i].size(); j++)
	   {
		   int w = g[i][j].second; int to = g[i][j].first;
		   if (i < to) continue;
		   if ( l - d[i] < w && l - d[i] > 0 ) { add(i,sz,l-d[i]); add(to,sz,w-l+d[i]); sz++; }
		   if ( l - d[to] < w && l - d[to] > 0 && w-l+d[to]!=l-d[i]) { add(to,sz,l-d[to]); add(i,sz,w-l+d[to]); sz++; }
	   }
   
	   
   q.insert(make_pair(d[s],s));
   for (int i=1; i<sz; i++) d[i] = inf;
   d[s] = 0;
   while (!q.empty())
   {
	   
	   int v = q.begin()->second;
	   q.erase(q.begin());
	   for (int i=0; i<(int)g[v].size(); i++)
	   {
		   int to = g[v][i].first;
		   int w = g[v][i].second;
		   if (d[v] + w < d[to])
		   {
			   q.erase(make_pair(d[to],to));
			   d[to] = d[v] + w;
			   q.insert(make_pair(d[to],to));
		   }
	    }
   }
   
   for (int i=1;i<sz;i++) 
	   if (d[i] == l) res++;
   cout << res;
   return 0;
}