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

int n;
unsigned int b[110][110];
unsigned int a[110];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset(a, 0, sizeof a);
  cin >> n;
  forn(i, n)
    forn(j, n) {
        scanf("%d", &b[i][j]);
        if  (i == j) continue;
        for (unsigned int k = 0; k <= 31; k++)
            if  (b[i][j] & (1 << k))
                a[i] |= (1 << k), a[j] |= (1 << k);
    }

  forn(i, n)
    printf("%d ", a[i]);
  return 0;
}