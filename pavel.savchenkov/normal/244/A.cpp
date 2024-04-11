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
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define sz(A) ((int)(A).size())
#define y1 asxfdsfs
#define y0 dsfgdfggdf

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

bool used[1000];
int n, k;
int a[40];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset(used, 0, sizeof used);
  cin >> n >> k;
  forn(i, k) scanf("%d", a + i), used[a[i] - 1] = 1;

  forn(i, k) {
    printf("%d ", a[i]);
    int c = 0;
    for (int j = 0; c < n - 1; j++)
        if  (!used[j]) {
            used[j] = 1;
            printf("%d ", j + 1); c++;
        }
  }
  return 0;
}