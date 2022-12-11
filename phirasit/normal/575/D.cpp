#include <iostream>

using namespace std;

const int N = 1000;

int main() {
  cout << (2 * N - 1) << endl;
  for(int i = 1;i <= N;i++) {
    cout << i << " " << 1 << " " << i << " " << 2 << endl;
  }
  for(int i = 2;i <= N;i++) {
    cout << i << " " << 1 << " " << i << " " << 2 << endl;
  }
  return 0;
}