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
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
vi id;
int where[300500];

int get(int a)
{
    int l = 0; int r = (int)id.size();
    while (l != r - 1)
    {
        int m = (l + r) >> 1;
        if (id[m] <= a) l = m; else r = m;
    }
    return l;
}

pii z[200500];
int szz = 0;
int n, m, h;
i64 res = 0;
vi g[200500];
vi fen[200500];
int szg = 0;
bool was[200500];
pii w[200500];

void inc(int ig,int i, int d)
{
//  cout << "in " << i << " na " << d << endl;
    for (; i < (int)g[ig].size(); i = (i|(i+1)) )
        fen[ig][i] += d;
}

int sum(int ig, int r)
{
    int res = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        res += fen[ig][r];
    return res;
}

int sum (int ig, int l, int r)
{
    return sum(ig, r) - sum(ig, l - 1);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> h >> m >> n; scanf("\n");
  forn(i, n)
  {
    char c = getchar();
    if (c == '+') 
    { 
        int _id, _hash; scanf("%d%d\n",&_id,&_hash); 
        id.pb(_id);
        z[szz].f = _id; z[szz].s = _hash; szz++;
    } else
    {
        int _id; scanf("%d\n",&_id);
        z[szz].f = _id; z[szz].s = -1; szz++;
    }
  }
  sort(id.begin(),id.end());
  id.resize( unique(id.begin(),id.end()) - id.begin() );
  memset(was,0,sizeof(was));

  forn(i, h)
  {
    if (was[i]) continue;
    was[i] = 1;
    g[szg].pb(i); w[i] = mp(szg, 0); fen[szg].pb(0);
    int now = (i + m) % h; int iter = 1;
    while (now != i)
    {
        g[szg].pb(now); was[now] = 1; w[now] = mp(szg, iter); fen[szg].pb(0);
        now = (now + m) % h;
        iter++;
    }
    int _sz = (int)g[szg].size();
    forn(j, _sz)
        g[szg].pb(g[szg][j]), fen[szg].pb(0);
    szg++;
  }
  
  /*
  forn(i, szg)
  {
    forn(j, g[i].size())
        cout << g[i][j] << " ";
    cout << endl;
  }
   */
  
  
  forn(i, szz)
   if (z[i].s > -1)
   {
        int nid = get(z[i].f);
//      cout << nid << " " << z[i].s << endl; 
        int t = z[i].s;
        int _sz = (int)g[w[t].f].size() / 2;
        int l = w[t].s; int r = l + _sz;
//      cout << "l = " << l << " r = " << r << endl;
        if (sum(w[t].f, w[t].s, w[t].s) == 0)
        {
          inc(w[t].f, w[t].s, 1); inc(w[t].f, (w[t].s + _sz)%(_sz*2), 1);
          where[nid] = g[w[t].f][w[t].s];
//        forn(j, g[w[t].f].size())
//          cout << sum(w[t].f,j,j) << " "; cout << endl;
//        cout << "res - >" << 0 << endl << endl;;
          continue;
        }
        
        while (l != r - 1)
        {
            int mid = (l + r) >> 1;
            if (sum(w[t].f, w[t].s, mid) == mid - w[t].s + 1) l = mid; else r = mid;
        }
        l = (l + 1) %(_sz + _sz);
        inc(w[t].f, l, 1); inc(w[t].f, (l + _sz)%(_sz*2), 1);
        where[nid] = g[w[t].f][l];
        res += l - w[t].s;
//      forn(j, g[w[t].f].size())
//          cout << sum(w[t].f,j,j) << " "; cout << endl;
//      cout << "l = " << l << endl;
//      cout << "res - >" << l - w[t].s << endl << endl;;
   } else
   {
       int nid = get(z[i].f);
//     cout << "del " << nid << endl;
//     cout << nid << endl;
       int j = where[nid];
       int _sz = ((int)g[w[j].f].size() / 2);
       inc(w[j].f, w[j].s, -1); inc(w[j].f, (w[j].s + _sz)%(_sz*2), -1);
//     forn(j, g[0].size())
//          cout << sum(0,j,j) << " "; cout << endl;
//    cout << endl;
   }
  
  cout << res << endl;
  return 0;
}