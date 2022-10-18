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
char s[1000000];
int s1[1000000];
int s2[1000000];
int a[1000000];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  gets(s);
  int n = (int)strlen(s);
  memset(s1,0,sizeof(s1));
  memset(s2,0,sizeof(s2));
  for (int i=0; s[i]; i++)
    if (s[i] >= 'a' && s[i]<='z') a[i] = 0, s1[i] = 0; else a[i] = 1, s1[i] = 1;
  
  s2[n-1] = a[n-1];
  for (int i=1; i<n; i++)
    s1[i] += s1[i-1];
  for (int i=n-2; i>=0; i--)
    s2[i] = a[i] + s2[i+1];
  int res = min(s1[n-1],n - s1[n-1]);
  forn(i,n-1)
    res = min(res,i + 1 - s1[i] + n - i - 1 - (n - i - 1 - s2[i+1]) );
    
  cout << res << endl;
  return 0;
}