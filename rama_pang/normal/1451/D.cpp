#include <bits/stdc++.h>
using namespace std;

void Main() {
  int d, k;
  cin >> d >> k;
  
  int lo = 0, hi = d / k + 5;
  while (lo < hi) {
    int md = (lo + hi + 1) / 2;
    if (2ll * md * k * md * k <= 1ll * d * d) {
      lo = md;
    } else {
      hi = md - 1;
    }
  }

  int state = 0;
  if (1ll * lo * k * lo * k + 1ll * (lo + 1) * k * (lo + 1) * k <= 1ll * d * d) {
    state = 1;
  }
  if (state) {
    cout << "Ashish\n";
  } else {
    cout << "Utkarsh\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}