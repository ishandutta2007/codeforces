#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a + b) % 2) {
      if ((a + d) && (b + c))
        cout << "Ya Ya Tidak Tidak" << '\n';
      if ((a + d) && !(b + c))
        cout << "Ya Tidak Tidak Tidak" << '\n';
      if (!(a + d) && (b + c))
        cout << "Tidak Ya Tidak Tidak" << '\n';
    } else {
      if ((a + d) && (b + c))
        cout << "Tidak Tidak Ya Ya" << '\n';
      if ((a + d) && !(b + c))
        cout << "Tidak Tidak Tidak Ya" << '\n';
      if (!(a + d) && (b + c))
        cout << "Tidak Tidak Ya Tidak" << '\n';
    }
  }
  return 0;
}