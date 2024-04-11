//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int pos = n - 1; pos >= 1; pos--) {
    if (k > n - pos)
      k -= n - pos;
    else {
      for (int i = 1; i < pos; i++)
        printf("a");
      printf("b");
      int bpos = n - k + 1;
      for (int i = pos + 1; i < bpos; i++)
        printf("a");
      printf("b");
      for (int i = bpos + 1; i <= n; i++)
        printf("a");
      printf("\n");
      return 0;
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
  scanf("%d", &q);
	while (q--)
		solve();
	return 0;
}