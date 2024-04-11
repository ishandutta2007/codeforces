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
int n;
struct _x
{
	int p,t;
	_x() {};
	friend bool operator <(const _x &a,const _x &b) 
	{
		if (a.p != b.p) return a.p > b.p;
		return a.t < b.t;
	}
};
_x x[100];
int k;

int main() {
  // freopen("input.txt","r",stdin);
  cin >> n >> k;
  forn(i,n) cin >> x[i].p >> x[i].t;
  sort(x,x+n);
  int res = 1;
  int j = k - 1;
  while (j >= 0 && x[j].p == x[k-1].p && x[j].t == x[k-1].t) j--;
  j++; res += k-1-j;
  j = k - 1;
  while (j < n && x[j].p == x[k-1].p && x[j].t == x[k-1].t) j++;
  j--;
  res += j-k+1;
  
  cout << res << endl;
  return 0;
}