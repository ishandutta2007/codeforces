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

const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

vi r;
string s;

void ReadTable(int id, int & FinalId);

string GetTag(int id)
{
   string res = ""; id++;
   while (s[id] != '>') res += s[id], id++;
   return res;
}

void ReadTd(int id, int & FinalId)
{
  string tag = GetTag(id);

  while (tag != "/td")
  {
   int NewId;
   ReadTable(id + 7, NewId); id = NewId;
   tag = GetTag(id);
  }

  FinalId = id + 5;
}

int ReadTr(int id, int & FinalId)
{
  int res = 0;
  string tag = GetTag(id);

  while (tag != "/tr")
  {
   int NewId;
   ReadTd(id + 4, NewId); id = NewId;
   res++;
   tag = GetTag(id);
  }

  FinalId = id + 5;
  return res;
}

void ReadTable(int id, int & FinalId)
{
  int res = 0;
  string tag = GetTag(id);

  while (tag != "/table")
  {
   int NewId;
   res += ReadTr(id + 4, NewId); id = NewId;
   tag = GetTag(id);
  }

  FinalId = id + 8;
  r.pb(res);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  char c; s.clear();
  while (scanf("%c", &c) >= 1) if  (c != ' ' && c != '\n') s += c;

//  printf("s = %s\n%s\n", s.c_str(), GetTag(0).c_str());
  int loose;
  ReadTable(7, loose);

  sort(r.begin(), r.end());
  forn(i, r.size())
   printf("%d ", r[i]);
  return 0;
}