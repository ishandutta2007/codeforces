#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

long long ships;
void origami(long long a, long long b) {
  if (a == 0 || b == 0) {
    return;
  }
  if (a == b) {
    ++ships;
  } else {
    long long addedShips = a / b;
    ships += addedShips;
    origami(b, a - addedShips*b);
  }
}


int main() {
  long long a, b;
  cin >> a >> b;
  origami(a,b);
  cout << ships << endl;
}