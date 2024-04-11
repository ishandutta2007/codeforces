#include <bits/stdc++.h>
using namespace std;


int main() {
  auto Query = [&](int x) {
    cout << "? " << x + 1 << endl;
    int in; cin >> in;
    return in;
  };

  auto Answer = [&](int x) {
    cout << "! " << (x == -1 ? x : x + 1) << endl;
    exit(0);
  };

  int n;
  cin >> n;

  if (n % 4 != 0) Answer(-1);
  
  int fs = Query(0);
  int sc = Query(n / 2);

  int lo = 0, hi = n / 2 - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int a1 = Query(mid);
    int a2 = Query(mid + n / 2);
    if (a1 == a2) {
      Answer(mid);
      return 0;
    } else if  (a1 < a2) {
      if (fs < sc) lo = mid + 1;
      if (fs > sc) hi = mid - 1;
    } else if (a1 > a2) {
      if (fs < sc) hi = mid - 1;
      if (fs > sc) lo = mid + 1;
    }
  }

  Answer(-1);
}