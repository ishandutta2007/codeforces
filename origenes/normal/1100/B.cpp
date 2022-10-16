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

int n, m, a;
map<int, int> cnt;

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    scanf("%d", &a);
    cnt[a]++;
    if (cnt.size() == n) {
      vector<int> tmp;
      for (auto &it : cnt) {
        it._2--;
        if (!it._2) tmp.eb(it._1);
      }
      putchar('1');
      for (auto it : tmp) cnt.erase(it);
    } else putchar('0');
  }
}