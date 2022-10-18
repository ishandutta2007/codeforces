#include <iostream>
#define i64 long long

using namespace std;

int main() {
 i64 x; cin >> x;
 if (x < 0) x = -x;
 i64 n = 0; int i = 0;
 while (n < x || (n-x)%2 == 1) { i++; n+=i; }
    cout << i;
  return 0;
}