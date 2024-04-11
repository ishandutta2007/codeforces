#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define reset(a, b) memset(a, b, sizeof(a))
#define _1 first
#define _2 second
#define eb emplace_back
typedef long long ll;
using namespace std;

const double pi = acos(-1);

int n, r;
double ans;

int main() {
  scanf("%d%d", &n, &r);
  double s = sin(pi / n);
  printf("%.10lf", s / (1 - s) * r);
}