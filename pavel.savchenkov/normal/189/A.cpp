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
const int int_inf = 2147483640;
const i64 i64_inf = 9223372036854775800ll;
const double pi = acos(-1.0);

using namespace std;
int a[3];
int n;
int res = 0;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n; forn(i, 3) cin >> a[i];
  sort(a, a + 3);
  
  for (int i1 = n / a[0]; i1 >= 0; i1--)
    for (int i2 = (n - i1 * a[0]) / a[1]; i2 >= 0; i2--)
        if  ( (n - i1 * a[0] - i2 * a[1]) % a[2] == 0 )
            res = max(res, i1 + i2 + (n - i1 * a[0] - i2 * a[1]) / a[2]);

  cout << res << endl;
  return 0;
}