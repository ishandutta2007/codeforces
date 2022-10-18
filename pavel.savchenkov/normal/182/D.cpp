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
char s1[101000];
char s2[101000];

bool c1[100100];
bool c2[100100];
int z[100100];

int main() {
  memset(c1,0,sizeof(c1));
  memset(c2,0,sizeof(c2));
  gets(s1);
  gets(s2);
  z[0] = 0;
  int n = (int)strlen(s1);
  int l = 0; int r = 0;
  foran(i,1,n)
  {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s1[z[i]] == s1[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
        if (z[i] + i == n && n % i == 0) c1[i-1] = 1;
  }
  c1[n-1] = 1;
  
  z[0] = 0;
  n = (int)strlen(s2);
  l = 0; r = 0;
  foran(i,1,n)
  {
        z[i] = 0;
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s2[z[i]] == s2[i+z[i]])
            z[i]++;
        if (i+z[i]-1 > r)
            l = i,  r = i + z[i] - 1;
        if (z[i] + i == n && n % i == 0) c2[i-1] = 1;
  }
  c2[n-1] = 1;
  
  int res = 0;
  for (int i=0; s1[i] && s2[i]; i++)
    if (s1[i] != s2[i]) break; else res += (int)(c1[i] && c2[i]);
  
  cout << res << endl;
  return 0;
}