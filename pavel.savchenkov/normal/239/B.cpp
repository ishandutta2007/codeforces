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
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 2 * (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);

using namespace std;

char S[110];
char s[110];

int next[110];
int prev[110];
int n, q;
int C[20];

bool digit(char c) {
    return c >= '0' && c <= '9';
}

void go(int l, int r) {
  memset(C, 0, sizeof C);
  int CP = l;
  int DP = 0;
  for (int i = l; i <= r; i++)
    next[i] = i + 1, prev[i] = i - 1, s[i] = S[i];

  while (CP >= l && CP <= r)
    if  (digit(s[CP])) {
        if  (s[CP] > '0') {
            C[s[CP] - '0']++;
            s[CP]--;
            CP = (DP == 0) ? next[CP] : prev[CP];
        }
        else {
            C[0]++;
            next[prev[CP]] = next[CP];
            prev[next[CP]] = prev[CP];
            CP = (DP == 0) ? next[CP] : prev[CP];
        }
    } else {
        DP = (s[CP] == '<') ? 1 : 0;
        int nextCP = (DP == 0) ? next[CP] : prev[CP];
        if  (nextCP < l || nextCP > r) break;
        if  (!digit(s[nextCP]))
            next[prev[CP]] = next[CP],
            prev[next[CP]] = prev[CP];
        CP = nextCP;
    }
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d%d\n", &n, &q);
  gets(S);
  forn(i, q) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--; r--;
    go(l, r);
    forn(i, 10) printf("%d ", C[i]);
    puts("");
  }
  return 0;
}