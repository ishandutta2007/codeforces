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
vector <int> g[1000010];
int name[1000010];
int p[20];
vector <int> s;
int num = 1;
char z[20000];
queue <pii> q;

void build(string str)
{

    int len = (int)str.length();
    int hash = str[0] - 'a' + 1;
    for (int i=1; i<len; i++) if (str[i] != '/') hash += (str[i] - 'a' + 1) * p[i];
    name[num] = hash; 
    
    if (str[0] == '/')
        s.pop_back();
    else
    {
        g[*s.rbegin()].pb(num); s.pb(num); num++; 
    }
    if (*str.rbegin() == '/')  s.pop_back();

}

int x[210];
int m; int n;
int ans;

void bfs()
{
    q.push(mp(0,0));
    while (!q.empty())
    {
        pii c = q.front(); q.pop();
        int ind = c.s; int v = c.f;
        forn(i,g[v].size())
        {
         int to = g[v][i];
         if (name[to] != x[ind]) { q.push(mp(to,ind)); continue; }
         if (ind == n) q.push(mp(to,ind)), ans++;  else q.push(mp(to,ind+1));
        }
    }       
}

int main() {
  p[0] = 1;
  for (int i=1; i<=10; i++) p[i] = p[i-1] * 29;
  
  char c; string str = ""; s.pb(0);
  while (1) 
  { 
      c = getchar(); 
      if (c == '\n') break;
      if (c == '<') continue;
      if (c == '>')
       build(str), str.clear(); else str += c;
  }
  

  cin >> m; scanf("\n");
  forn(i,m)
  {
    int len = 0; n = 0; int hash = 0; ans = 0; gets(z);
 
    for (int j=0; z[j]; j++)
    {
        if (z[j] < 'a' || z[j] > 'z') { x[n] = hash; len = 0; n++; hash = 0; continue; }
        hash += (z[j] - 'a' + 1) * p[len]; len++;
    }
    x[n] = hash;
    bfs();
    printf("%d\n",ans); 
  }
  
  return 0;
}