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
/*----------------------------------------------------------------------------------------------*/

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  i64 n; i64 step; cin >> step;
  n = 3ll * (step - 1ll) + 1ll;
  i64 res = n*n + n; res /= 2ll;
  for (i64 i=1; i<step; i++) res += 3ll*i;
  cout << res << endl;
  return 0;
}