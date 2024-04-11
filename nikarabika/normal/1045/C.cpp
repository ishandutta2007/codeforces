//In the Name of God
//Ya Ali

#include <bits/stdc++.h>

#define err(A) cout << #A << " = " << (A) << endl

using namespace std;

const int maxn = 131072;
const int mxlg = 18;

int n, m, Q;

vector<int> g[maxn];

int h[maxn];
int d[maxn][mxlg];

map<pair<int, int>, bool> hase;

void bfs()
{
  memset(h, -1, sizeof h);
  
  vector<int> q;
  q.push_back(0);
  h[0] = 0;

  for (int i = 0; i < q.size(); i ++)
    {
      int v = q[i];
      for (int u: g[v])
	if (h[u] == -1)
	  {
	    h[u] = h[v] + 1;
	    d[u][0] = v;
	    for (int j = 1; j < mxlg; j ++)
	      d[u][j] = d[d[u][j - 1]][j - 1];
	    q.push_back(u);
	  }
    }
}

int dad(int v, int H)
{
  for (int i = mxlg; i --; )
    if (h[d[v][i]] >= H)
      v = d[v][i];
  return v;
}

int lca(int v, int u)
{
  if (h[v] > h[u])
    swap(v, u);
  if (h[v] != h[u])
    u = dad(u, h[v]);
  if (v == u)
    return v;
  for (int i = mxlg; i --; )
    if (d[v][i] != d[u][i])
      v = d[v][i], u = d[u][i];
  return d[v][0];
}

void adde(int v, int u)
{
  hase[{v, u}] = hase[{u, v}] = true;
  g[v].push_back(u);
  g[u].push_back(v);
}

int dis(int v, int u)
{
  int D = lca(v, u);
  int ret = h[v] + h[u] - 2 * h[D];
  if (v == D or u == D)
    return ret;
  int dv = dad(v, h[D] + 1);
  int du = dad(u, h[D] + 1);
  return ret - hase[{dv, du}];
}

int main()
{
  scanf("%d%d%d", &n, &m, &Q);

  for (int i = 0; i < m; i ++)
    {
      int v, u;
      scanf("%d%d", &v, &u);
      adde(-- v, -- u);
    }

  bfs();

  for (; Q --; )
    {
      int v, u;
      scanf("%d%d", &v, &u);
      v --, u --;
      printf("%d\n", dis(v, u));
    }
  
  return 0;
}