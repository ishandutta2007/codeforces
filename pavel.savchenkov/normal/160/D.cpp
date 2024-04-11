#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <memory.h>
#define pb push_back
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)

using namespace std;

struct edge
{
	int u,v,w,id;
	edge() {};
	edge(int _u,int _v,int _w,int _id) { u = _u; v = _v; w = _w; id = _id; }
	friend bool operator <(const edge &a,const edge &b) { return a.w < b.w; };
};
int n,m;
edge a[100500];
int p[100500];
int size[100500];
string res[100500];
int id[100500];
int tin[100500];
int up[100500];
int timer = 0;

int get_set(int i)
{
	if (p[i] == i) return i;
	return p[i] = get_set(p[i]);
}

void union_set(int i,int j)
{
	i = get_set(i);
	j = get_set(j);
	if (i == j) return;
	if (size[i] > size[j]) swap(i,j);
	p[i] = j; size[j] += size[i];
}

void dfs(int v,int parent,vector < pair<int,int> > *g,bool *was)
{
	was[v] = 1;
	tin[v] = up[v] = timer++;
	forn(i,(int)g[v].size())
	{
		int to = g[v][i].first;
		if (to == parent) continue;
		if (was[to]) { up[v] = min(up[v],tin[to]); continue; }
		dfs(to,v,g,was);
		up[v] = min(up[v],up[to]);
		if (tin[v] < up[to]) res[ g[v][i].second ] = "any";
	}
}

void go(int l,int r)
{
	vector <int> c;
	foran(i,l,r+1) a[i].u = get_set(a[i].u), a[i].v = get_set(a[i].v), c.pb(a[i].v), c.pb(a[i].u);
	sort(c.begin(),c.end());
	c.resize( unique(c.begin(),c.end()) - c.begin() );
	forn(i,(int)c.size()) id[ c[i] ] = i;
	
	vector < pair<int,int> > g[(int)c.size() + 10];

    foran(i,l,r+1) if (id[a[i].u] != id[a[i].v])
		           g[ id[a[i].v] ].pb( make_pair(id[a[i].u],a[i].id) ), 
		           g[ id[a[i].u] ].pb( make_pair(id[a[i].v],a[i].id) );
	
	forn(i,(int)c.size()) sort(g[i].begin(),g[i].end());

	forn(i,(int)c.size())
	 forn(j,(int)g[i].size())
      res[ g[i][j].second ] = "at least one";
	  
    bool was[(int)c.size() + 10];
	memset(was,false,sizeof(was));
	timer = 0;
	forn(i,(int)c.size()) if (!was[id[c[i]]]) dfs(id[c[i]],-1,g,was);
	
	forn(i,(int)c.size())
		foran(j,1,(int)g[i].size())
		{
			int to = g[i][j].first;
			if (to == g[i][j-1].first) res[ g[i][j-1].second ] = "at least one", res[ g[i][j].second ] = "at least one";
		}
}

int main() {
  scanf("%d%d",&n,&m);
  forn(i,m)
  {
	scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w); a[i].id = i;
	res[i] = "none";
  }
  sort(a,a+m);
  memset(size,0,sizeof(size));
  foran(i,1,n+1) p[i] = i;
  
  forn(i,m)
  {
	int j = i; int l = i;
	while (a[j].w == a[i].w && j < m) j++;
	go(l,j-1); i = j - 1;
	foran(k,l,j) if ( get_set(a[k].u) != get_set(a[k].v) ) union_set(a[k].u,a[k].v);
  }
  
  forn(i,m) puts(res[i].c_str());
  return 0;
}