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
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e5 + 10;

int n, m;
int a[MAXN];
int sum[MAXN];
int f[MAXN];

int prev[MAXN];
int next[MAXN];

int get_sum(int l, int r) {
  if  (l == 0) return sum[r];
  return sum[r] - sum[l - 1];
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  sum[0] = 0; f[0] = 0;
  for (int i = 1; i < n - 1; i++) 
  {
    if  (a[i - 1] == a[i])
      f[i] = f[i - 1];
    else {
      int j = i + 1;
      while (j < n - 1 && a[j] == a[i]) j++;
      
      if  (a[i - 1] > a[i] && a[i] < a[j]) 
        f[i] = 1;
      else
        f[i] = 0;
    }

    sum[i] = sum[i - 1] + f[i];
  }
  
  prev[0] = 0;
  for (int i = 1; i < n; i++)
    if  (a[i] == a[i - 1]) prev[i] = prev[i - 1]; else prev[i] = i - 1;

  next[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--)
    if  (a[i] == a[i + 1]) next[i] = next[i + 1]; else next[i] = i + 1;


  for (int i = 0; i < m; i++) {
    int l, r; scanf("%d %d", &l, &r);
    l--; r--;

    if  (r - l + 1 <= 2) {
      puts("Yes");
      continue;
    }

    l = next[l];
    r = prev[r];

    puts(l > r || get_sum(l, r) == 0 ? "Yes" : "No");
  }

  return 0;
}