#include <bits/stdc++.h>
using namespace std;

typedef long long int LLI;
typedef pair<LLI, int> Pair;

const LLI INF = 1e15;

int _N;
int N;
int K;
LLI ans;
LLI as[514514];
LLI ts[514514];
LLI cur[514514];
set<int> ord;
set<Pair> st;

int main() {
  scanf("%d%d", &K, &_N);
  for (int i=0; i<_N; i++) {
    scanf("%lld", &ts[i]);
  }
  sort(ts, ts+_N);

  N = _N-1;

  for (int i=0; i<N; i++) {
    as[i] = ts[i+1] - ts[i];
    st.insert(Pair(as[i], i));
    ord.insert(i);
    cur[i] = as[i];
  }

  for (int i=0; i<K; i++) {
    /*printf("%d:", i);
    for (Pair p : st) {
      printf(" (%lld, %d)", p.first, p.second);
    }puts("");
    printf("ord: ");
    for (int u : ord) {
      printf(" %d", u);
    }puts("");*/

    LLI c = -st.begin()->first;
    ans += -c;
    int idx = st.begin()->second;
    st.erase(st.begin());
    ord.erase(idx);

    bool nopush = false;
    auto itr = ord.upper_bound(idx);
    if (itr != ord.end()) {
      int f = *itr;
      ord.erase(f);
      auto itr2 = st.lower_bound(Pair(cur[f], f));
      c += itr2->first;
      st.erase(itr2);
    } else {
      nopush = true;
    }

    itr = ord.lower_bound(idx);
    if (itr != ord.begin()) {
      itr--;
      int f = *itr;
      ord.erase(f);
      auto itr2 = st.lower_bound(Pair(cur[f], f));
      c += itr2->first;
      st.erase(itr2);
    } else {
      nopush = true;
    }

    if (nopush) continue;

    cur[idx] = c;
    st.insert(Pair(cur[idx], idx));
    ord.insert(idx);
  }

  printf("%lld\n", ans);
}