//HACK ME, PLEASE! ^_^
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>

#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000ll;
const double pi = acos(-1.0);

using namespace std;
struct vertex
{
    int ntr, id; vii c;
    vertex() {};
};

struct fenvick
{
    int sz;
    vi tree;
    void inc(int i,int d)
    {
        for (; i < sz; i = ((i + 1) | i) )
            tree[i] += d;
    };
    
    int sum(int r)
    {
        int res = 0;
        for (; r>=0; r = ((r + 1) & r) - 1)
            res += tree[r];
        return res;
    };
    
    int sum(int l,int r)
    {
        return sum(r) - sum(l - 1);
    };
    
    fenvick (int _sz)
    {
        tree.assign(_sz + 10, 0);
        sz = _sz + 10;
    };
};

vector <fenvick> tr;
vertex g[100500];
int root;
pii edges[100500];
int n, m;

void dfs(int v, int par, int ntr, int id)
{
//  cout << "in " << v << " with " << ntr << " " << id << endl; 
    g[v].ntr = ntr;
    g[v].id = id;
    
    if ((int)g[v].c.size() == 1) { tr.pb( fenvick (id + 1) ); return; }
    
    forn(i, (int)g[v].c.size())
        if  (g[v].c[i].f != par) edges[g[v].c[i].s] = mp(ntr, id + 1), dfs(g[v].c[i].f, v, ntr, id + 1);
}

int go(int a,int b)
{
    if (a == b) return 0;
//  cout << "-> " << a + 1 << " " << b + 1 << endl;
    if (b == root) swap(a, b);
    if (a == root)
    {
        if (tr[g[b].ntr].sum(g[b].id) == 0) return g[b].id + 1;
        return -1;
    }
    
    if  (g[a].ntr == g[b].ntr)
    {
        int tree = g[a].ntr;
        if (g[a].id > g[b].id) swap(a, b);
        if (tr[tree].sum(g[a].id + 1, g[b].id) == 0) return g[b].id - g[a].id;
        return -1;
    }
    
//  cout << "sum (" << g[a].id << " " << g[b].id << ") = " 
//   << tr[g[a].ntr].sum(g[a].id) << " " << tr[g[b].ntr].sum(g[b].id) << endl;
    
    if (tr[g[a].ntr].sum(g[a].id) + tr[g[b].ntr].sum(g[b].id) == 0) return g[a].id + g[b].id + 2;
    return -1;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  int ma = 0;
  
  forn(i, n - 1)
  {
    int u, v; scanf("%d%d",&u,&v);
    u--; v--;
    g[u].c.pb(mp(v,i));
    g[v].c.pb(mp(u,i));
    if  ((int)g[u].c.size() >= (int)g[ma].c.size()) ma = u;
    if  ((int)g[v].c.size() >= (int)g[ma].c.size()) ma = v;
  }
  root = ma;
//  cout << "root = " << root << endl;
  int ntree = 0;
  forn(i, (int)g[root].c.size())
   dfs(g[root].c[i].f, root, ntree, 0), edges[g[root].c[i].s] = mp(ntree,0), ntree++;
  
//  forn(i, n)
//      if  (i != root) cout << i + 1 << " -> " << g[i].ntr << " " << g[i].id << endl;
  
  int m;
  cin >> m;
  int type;
  
  forn(i, m)
  {
   scanf("%d",&type);
   if (type == 1)
   {
       int id; scanf("%d",&id); id--;
       tr[edges[id].f].inc(edges[id].s, -1);
   } else if (type == 2)
   {
       int id; scanf("%d",&id); id--;
       tr[edges[id].f].inc(edges[id].s, 1);
   } else
   {
       int a, b;
       scanf("%d%d",&a,&b);
       printf("%d\n",go(a-1, b-1));
   }
  }
  return 0;
}