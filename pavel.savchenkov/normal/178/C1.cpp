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
int id[300500];
int szid = 0;
int hash[200500];
int szhash = 0;
int where[300500];

int get(int a)
{
    int l = 0; int r = szid;
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
        id[szid] = _id; szid++;
        z[szz].f = _id; z[szz].s = _hash; szz++;
    } else
    {
        int _id; scanf("%d\n",&_id);
        z[szz].f = _id; z[szz].s = -1; szz++;
    }
  }
  sort(id, id + szid);
  memset(hash, -1, sizeof(hash));
  
//  forn(i ,szz)
  // cout << z[i].f << " " << z[i].s << endl;
   
  forn(i, szz)
   if (z[i].s > -1)
   {
//      cout << z[i].f << " " << z[i].s << endl;
        int nid = get(z[i].f);
        int t = z[i].s;
        forn(j ,n + 1)
            if (hash[(t + j * m) % h] == -1) 
             { hash[(t + j * m) % h] = nid; where[nid] = (t + j * m) % h; res += j; break; }
   } else
   {
       int nid = get(z[i].f);
       hash[where[nid]] = -1;
   }
  
  cout << res << endl;
  return 0;
}