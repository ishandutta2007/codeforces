#include <bits/stdc++.h>
using namespace std;

#define INF 0x7fffffff
typedef pair<int, int> Pair;

int n;
int k;
int ans;
int as[114514];
map<int, int> cnt;
set<Pair> lib;
set<int> appear[114514];

int main() {
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &as[i]);
    appear[as[i]].insert(i);
    appear[as[i]].insert(INF);
  }

  for (int i=0; i<n; i++) {
    if (lib.count(Pair(*appear[as[i]].begin(), as[i]))) {
      lib.erase(Pair(*appear[as[i]].begin(), as[i]));
      appear[as[i]].erase(i);
      lib.insert(Pair(*appear[as[i]].begin(), as[i]));
      continue;
    }

    ans++;
    if (lib.size() == k) {
      lib.erase(*lib.rbegin());
    }

    appear[as[i]].erase(i);
    lib.insert(Pair(*appear[as[i]].begin(), as[i]));
  }

  printf("%d\n", ans);
}