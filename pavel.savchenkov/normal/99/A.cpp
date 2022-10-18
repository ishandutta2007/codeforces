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
#define sqr(x) (x) * (x)

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);
 
using namespace std;

string s[2];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  char c; int i = 0;
  while (1)
  {
	c = getchar();
	if (c == '\n') break;
	if (c == '.') i++; else s[i] += c;
  }
  if (*s[0].rbegin() == '9') { puts("GOTO Vasilisa."); return 0; }
  if (s[1][0] >= '5')
  {	  
	  s[0][(int)s[0].length() - 1] = *s[0].rbegin() + 1;
	  cout << s[0];
  } else
    cout << s[0];
  return 0;
}