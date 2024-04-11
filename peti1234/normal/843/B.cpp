#include <bits/stdc++.h>
using namespace std;
const int c=500002;
int ert[c], kov[c];
int n, start, x, legjobbhely, ertek=-1;
int valaszert=2e9, valaszhely;
void kerd(int a) {
  cout.flush() << "? " << a << "\n";
  cin >> ert[a] >> kov[a];
  if (kov[a]==-1) {
    kov[a]=a;
  }
  if (ert[a]<valaszert && ert[a]>=x) {
    valaszert=ert[a];
    valaszhely=a;
  }
  if (ert[a]>ertek && ert[a]<x) {
    legjobbhely=a;
    ertek=ert[a];
  }
}
int vel() {
  long long x=rand(), y=rand();
  return (x*y)%n+1;
}
int main() {
  cin >> n >> start >> x;
  kerd(start);
  srand (time(NULL));
  for (int i=1;i<1000; i++) {
    kerd(vel());
  }
  if (legjobbhely) {
      for (int i=1; i<1000; i++) {
        legjobbhely=kov[legjobbhely];
        kerd(legjobbhely);
      }
  }
  if (!valaszhely) valaszert=-1;
  cout << "! " << valaszert << "\n";
return 0;
}