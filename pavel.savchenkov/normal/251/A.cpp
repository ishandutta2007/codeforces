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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

int x[100500];
int n, d;

LL C(int _N) {
  LL N = (LL)_N;
  return N * (N - 1LL) / 2LL;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> d;
  for (int i = 0; i < n; i++)
    scanf("%d", &x[i]);

  LL res = 0;
  for (int i = 0; i < n; i++) {
    int j = lower_bound(x + i, x + n, x[i] + d) - x;
    if  (j == n) j--;
    if  (x[j] > d + x[i]) j--;
    if  (j < 0) continue;

    res += C(j - i);
  }

  cout << res << '\n';
  return 0;
}