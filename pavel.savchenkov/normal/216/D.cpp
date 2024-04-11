#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define i64 long long
#define ui64 unsigned long long
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
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 0x7FFFFFFE;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFELL;
const double PI = acos(-1.0);

using namespace std;

vi v[1010];

int get(int id, int l, int r)
{
 int pos1 = lower_bound(v[id].begin(), v[id].end(), l) - v[id].begin();
 int pos2 = lower_bound(v[id].begin(), v[id].end(), r) - v[id].begin();

 if  (pos2 == 0) return 0;
 return max(0, pos2 - pos1);
}

int ans = 0;
int n;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  forn(i, n)
  {
   int k;
   scanf("%d", &k);
   v[i].assign(k, 0);
   forn(j, k)
    scanf("%d", &v[i][j]);

   sort(v[i].begin(), v[i].end());
  }

  forn(i, n)
   forn(j, v[i].size() - 1)
    if  (get((i + 1) % n, v[i][j], v[i][j + 1]) != get((i - 1 + n) % n, v[i][j], v[i][j + 1])) ans++;

  cout << ans << '\n'; 
  return 0;
}