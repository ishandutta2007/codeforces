#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int p1,p2,p3,p4,a,b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  b=max(a-1,min(b,min(p1-1,min(p2-1,min(p3-1,p4-1)))));
  cout << (b - a + 1) << endl;
}