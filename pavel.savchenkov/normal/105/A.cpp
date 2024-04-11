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
int n,m,k;
vector < pair <string,int> > res;
string s;
int x;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d%d 0.%d\n",&n,&m,&k);
  
  forn(i,n)
  {
    s.clear();
    char c='.'; while (1) { c=getchar(); if (c!=' ') s += c; else break; }
    scanf("%d\n",&x);
    if (k * x / 100 < 100) continue;
    res.pb(mp(s,k * x / 100));
  }
  
  forn(i,m)
  {
    getline(cin,s); int j=0;
    for( ;j<(int)res.size(); j++)
        if (res[j].f == s) break;
    if (j == (int)res.size()) res.pb(mp(s,0));
  }
  
  sort(res.begin(),res.end());
  
  printf("%d\n",(int)res.size());
  forn(i,res.size())
    printf("%s %d\n",res[i].f.c_str(),res[i].s);
  return 0;
}