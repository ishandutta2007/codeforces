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

struct procedure
{
    string name; int t;
    vector <string> types;
    procedure() { t = 0;  }
    procedure(string _n) { name=_n; t = 0; }

    void add(string _type)
    {
        types.pb(_type); t++;
    };

    friend bool operator <(const procedure & a, const procedure & b)
    {
        return a.name < b.name;
    };
};

pair <string, string> var[1100];
procedure p[1100];

int n, m, k;

int res = 0;


string gettype(string name)
{
   int l = 0; int r = m;
   while (l != r - 1)
   {
       int M = (l + r) >> 1;
       if  (var[M].f <= name) l = M; else r = M;
   }
   return var[l].s;
}

void go(procedure a, procedure b)
{
  if  (a.t != b.t) return;
  forn(i, a.t)
   if  (b.types[i] != "T" && gettype(a.types[i]) != b.types[i]) return;

  res++;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d\n", &n);
  forn(i, n)
  {
    string s = ""; string name = "";
    char c;
    while(1)
    {
        c = getchar();
        if  (c == '\n') break;
        if  (c != ' ') s += c;
    }
    int pos = 4;
    for (; s[pos] != '('; pos++)
     name += s[pos];
    p[i].name = name;

    while (1)
    {
        string type = ""; pos++;
        for (; s[pos] != ',' && s[pos] != ')'; pos++) type += s[pos];
        p[i].add(type);
        if  (s[pos] == ')') break;
    }
  }
  sort(p, p + n);

  scanf("%d\n", &m);
  forn(i, m)
  {
    string s = ""; string type = ""; string name = "";
    char c;
    while(1)
    {
        c = getchar();
        if  (c == '\n') break;
        if  (c != ' ') s += c;
    }

    bool was = 0;
    for (int pos = 0; pos < s.length(); pos++)
    {
        if  (was) { name += s[pos]; continue; }
        type += s[pos];
        if  (type == "int" || type == "double" || type == "string" || type == "T") was = 1;
    }

    var[i] = mp(name, type);
  }
  sort(var, var + m);


  scanf("%d\n", &k);
  forn(i, k)
  {
    string s = ""; string name = ""; procedure a;
    char c;
    while(1)
    {
        c = getchar();
        if  (c == '\n') break;
        if  (c != ' ') s += c;
    }
    int pos = 0;
    for (; s[pos] != '('; pos++)
     name += s[pos];
    a.name = name;

    while (1)
    {
        string type = ""; pos++;
        for (; s[pos] != ',' && s[pos] != ')'; pos++) type += s[pos];
        a.add(type);
        if  (s[pos] == ')') break;
    }

    res = 0;
    int l = lower_bound(p, p + n, name) - p;
    int r = upper_bound(p, p + n, name) - p;
    for (int j = l; j < r; j++)
     go(a, p[j]);

    printf("%d\n", res);
  }



  return 0;
}