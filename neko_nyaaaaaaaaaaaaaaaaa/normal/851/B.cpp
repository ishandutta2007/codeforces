#include <bits/stdc++.h>
using namespace std;

int main() {
      long long ax, ay, bx, by, cx, cy;
      cin >> ax >> ay >> bx >> by >> cx >> cy;
      long long a = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
      long long b = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy);
      long long c = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
      if (a == c && (a + c) * 2 != b) cout << "Yes";
      else cout << "No";
      return 0;
}