#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

int main(){
  int num = 1 << 7;
  cout << "? ";
  for (int i = 1; i <= 100; ++i)
    cout << i << ' ';
  cout << endl;
  int x1;
  cin >> x1;
  cout << "? ";
  for (int i = 1; i <= 100; ++i)
    cout << i * num << ' ';
  cout << endl;
  int x2;
  cin >> x2;
  cout << "! " << (x1 - x1 % num) + x2 % num << endl;
  return 0;
}