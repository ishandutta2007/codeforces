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

int d[2000];
int n;
int cnt[20000];

string solve()
{
  forn(i, (int)1e4 + 1)
	if (cnt[i] == n) return "Exemplary pages.";
  forn(i, n)
	foran(j, i + 1, n)
	{
		if (d[i] == d[j]) continue;
		int c = -1;
		forn(x, n)
			if (x != i && x != j) { c = x; break; }
        if (cnt[d[c]] != n - 2 && c != -1) continue;
		int a = i; int b = j;
		if (d[a] > d[b]) swap(a, b);
		if (c == -1)
		{
			if ( (d[b] - d[a]) % 2 != 0) continue;
			printf("%d ml. from cup #%d to cup #%d.", (d[b] - d[a])/2, a + 1, b + 1); exit(0);
		}
		if (d[b] - d[c] == d[c] - d[a] && d[b] - d[c] > 0)
		{ printf("%d ml. from cup #%d to cup #%d.", d[b] - d[c], a + 1, b + 1); exit(0); }
	}
  
  return "Unrecoverable configuration.";
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(cnt, 0, sizeof cnt);
  cin >> n;
  forn(i, n)
	cin >> d[i], cnt[d[i]]++;
  
  cout << solve();
  return 0;
}