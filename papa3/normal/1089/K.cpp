#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1000000000000000000ll

const int baza = 1<<20;

int mi[2*baza];
int to_push[2*baza];

void mi_akt(int co, int gdzie) {
  mi[gdzie] += co;
  to_push[gdzie] += co;
}

void zwal(int gdzie) {
  mi_akt(to_push[gdzie], gdzie*2);
  mi_akt(to_push[gdzie], gdzie*2+1);
  to_push[gdzie] = 0;
}

void mi_add(int co, int pyt_pocz, int pyt_kon, int pocz=0, int kon=baza, int gdzie=1) {
  if (kon <= pyt_pocz || pyt_kon <= pocz) {
    return;
  }
  if (pyt_pocz <= pocz && kon <= pyt_kon) {
    mi_akt(co, gdzie);
    return;
  }
  zwal(gdzie);
  int sr = (pocz+kon)/2;
  mi_add(co, pyt_pocz, pyt_kon, pocz, sr, gdzie*2);
  mi_add(co, pyt_pocz, pyt_kon, sr, kon, gdzie*2+1);
  mi[gdzie] = min( mi[gdzie*2], mi[gdzie*2+1]);
}

int mi_czyt(int pyt_pocz, int pyt_kon, int pocz=0, int kon=baza, int gdzie=1) {
  if (kon <= pyt_pocz || pyt_kon <= pocz) {
    return INF;
  }
  if (pyt_pocz <= pocz && kon <= pyt_kon) {
    return mi[gdzie];
  }
  int sr = (pocz+kon)/2;
  zwal(gdzie);
  return min(
    mi_czyt(pyt_pocz, pyt_kon, pocz, sr, gdzie*2),
    mi_czyt(pyt_pocz, pyt_kon, sr, kon, gdzie*2+1));
}

vector<pair<int, int> > pyt;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  for (int i=0; i<baza; i++) {
    mi[i+baza] = -i;
  }
  for (int i=baza-1; i>0; i--) {
    mi[i] = min(mi[i*2], mi[i*2+1]);
  }
  
  int n;
  cin >> n;
  pyt.push_back({});
  char c;
  int a, b;
  while (n--) {
    cin >> c >> a;
    if (c == '?') {
      cout << mi_czyt(a, a+1) - mi_czyt(0, a) + 1 << "\n";
    } else if (c == '+') {
      cin >> b;
      mi_add(b, a, baza);
    } else {
      mi_add(-pyt[a].second, pyt[a].first, baza);
    }
    pyt.push_back({a, b});
  }
  
  return 0;
}