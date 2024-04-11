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
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);
 
using namespace std;
 
int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  int n, m;
  cin >> n >> m;
  if (!n && !m) { puts("0 0"); return 0;}
  if (n == 0) { puts("Impossible"); return 0; }
  int mi = n + m - min(n, m);;
  int ma = n + m - min(1, m);
  cout << mi << " " << ma << endl;
  return 0;
}