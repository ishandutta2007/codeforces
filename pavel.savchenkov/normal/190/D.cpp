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

int n, k;
int a[500500];
int cnt[500500];
i64 ans = 0;

vi v;

int main() {
  cin >> n >> k;
  forn(i, n)
	scanf("%d",&a[i]), v.pb(a[i]);
  
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  forn(i, n)
	a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
  
  memset(cnt, 0, sizeof cnt);
  cnt[a[0]] = 1;
  
  int r = 0;
  for (int l = 0; l < n && r != n + 1; l++)
  {
	while (cnt[a[r]] != k && r < n) r++, cnt[a[r]]++;
	ans += n - r;
	cnt[a[l]]--;
  }
  
  cout << ans << endl;
  return 0;
}