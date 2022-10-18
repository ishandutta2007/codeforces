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
#include <assert.h>

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
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

struct pos
{
    string name; int gol1, gol2, p; bool was;
    pos() { was = 0; p=0; };
    pos(string _name, int g1, int g2, int _p) { name=_name; gol1=g1; gol2=g2; was=0; p=_p; }
    friend bool operator <(const pos & a, const pos & b)
    {
        if  (a.p != b.p) return a.p < b.p;
        if  (a.gol1 - a.gol2 != b.gol1 - b.gol2) return a.gol1 - a.gol2 < b.gol1 - b.gol2;
        if  (a.gol1 != b.gol1) return a.gol1 < b.gol1;
        return a.name > b.name;
    }
};

vector <pos> d;


void add(string name1, string name2, int x, int y)
{
 //   cout << name1 << " " << name2 << " " << x << " " << y << "\n";
    bool was1 = 0; bool was2 = 0;
    forn(i, d.size())
     if  (d[i].name == name1)
     {
         d[i].gol1 += x; d[i].gol2 += y; was1 = 1;
         if  (x > y) d[i].p += 3;
         if  (x == y) d[i].p += 1;
     } else if  (d[i].name == name2)
     {
         d[i].gol1 += y; d[i].gol2 += x; was2 = 1;
         if  (x < y) d[i].p += 3;
         if  (x == y) d[i].p += 1;
     }

     int p1 = 0;
     if  (x > y) p1 = 3; else if  (x == y) p1 = 1;
     int p2 = 0;
     if  (x < y) p2 = 3; else if  (x == y) p2 = 1;

     if  (!was1)
      d.pb(pos(name1, x, y, p1));
     if  (!was2)
      d.pb(pos(name2, y, x, p2));

     if  (name1 == "BERLAND")
      forn(i, d.size())
       if  (d[i].name == name2) d[i].was = 1;

     if  (name2 == "BERLAND")
      forn(i, d.size())
       if  (d[i].name == name1) d[i].was = 1;
}


void del(string name1, string name2, int x, int y)
{
    forn(i, d.size())
     if  (d[i].name == name1)
     {
         d[i].gol1 -= x; d[i].gol2 -= y;
         if  (x > y) d[i].p -= 3;
         if  (x == y) d[i].p -= 1;
     } else if  (d[i].name == name2)
     {
         d[i].gol1 -= y; d[i].gol2 -= x;
         if  (x < y) d[i].p -= 3;
         if  (x == y) d[i].p -= 1;
     }
}

char s[2][30];
string ss[2];

int X = -1; int Y = -1;

void upd(int x, int y)
{
    if  (X == -1) { X = x, Y = y; return; }
    if  (x - y > X - Y) return;
    if  (x - y < X - Y) { X = x; Y = y; return; }
    if  (y > Y) return;
    X = x; Y = y;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  forn(i, 5)
  {
      int x, y;
      scanf("%s %s %d:%d\n", &s[0], &s[1], &x, &y);
      forn(j, 2) ss[j].clear();
      forn(j, 2)
       for (int ii = 0; s[j][ii]; ii++)
        ss[j] += s[j][ii];
      add(ss[0], ss[1], x, y);
  }
  string need = "";
  forn(i, d.size())
   if  (d[i].name != "BERLAND" && !d[i].was) need = d[i].name;

  sort(d.begin(), d.end());

  for (int x = 0; x < 50; x++)
   for (int y = 0; y < x; y++)
   {
       add("BERLAND", need, x, y);
       sort(d.begin(), d.end());
       if  (d[2].name == "BERLAND" || d[3].name == "BERLAND")
         upd(x, y);
       del("BERLAND", need, x, y);
   }

  if  (X == -1) puts("IMPOSSIBLE"); else
   printf("%d:%d\n", X, Y);
  return 0;
}