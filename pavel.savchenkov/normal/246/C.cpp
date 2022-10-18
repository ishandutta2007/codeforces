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
#define y1 asxfdsfsdsjhfgidf
#define y0 dsfgdfggdfjdhriwurehiw

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

int n, k, K = 0;
int a[60];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> k;

  forn(i, n)
    scanf("%d", &a[i]);
  sort(a, a + n);

  for (int len = 1; len <= n && K < k; len++) {
    for (int j = n - len; j >= 0 && K < k; j--) {
        printf("%d ", len);
        for (int i = n - 1; i > n - len; i--)
            printf("%d ", a[i]);
        printf("%d\n", a[j]);
        K++;
    }
  }

  return 0;
}