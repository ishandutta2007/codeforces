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
vector <string> res;
char x[500500];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  string s = ""; string ss = "";
  gets(x); int l = (int)strlen(x);
  int i = 0;
  for (; i<l; i++)
    if (x[i] != '.') s += x[i]; else break;

  if (s.empty() || (int)s.length() > 8) { puts("NO"); return 0; }
  char c;
  
  for (int j=i+1; j<l; j++)
  {
    c = x[j]; 
    if (c != '.') { ss += c;  continue; }
    
    int len = (int)ss.length();
    if (len <= 1 || len > 11) { puts("NO"); return 0; }

    if (len <= 3) { res.pb(s + "." + ss.substr(0,len-1)); s = ss.substr(len-1,1), ss.clear(); continue; }
    
    res.pb(s + "." + ss.substr(0,3));  s = ss.substr(3,len-3); ss.clear();
    
  }
  if ((int)ss.length() > 3 || c == '.' || ss.empty()) { puts("NO"); return 0; }
  
  res.pb(s + "." + ss);
  
  puts("YES");
  forn(i,(int)res.size())
    printf("%s\n",res[i].c_str());
  return 0;
}