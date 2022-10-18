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
i64 res = 0;
int w, h;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> w >> h;
  for (int i=2; i<=h; i += 2)
	for (int j=2; j<=w; j += 2)
		res += (h - i + 1) * (w - j + 1);
  
  cout << res << endl;
  return 0;
}