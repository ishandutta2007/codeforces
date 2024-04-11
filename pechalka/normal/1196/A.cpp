#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>

using namespace std;

int main(){
  int q;
  cin >> q;
  for (int query = 0; query < q; ++query){
    long long a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c) / 2 << '\n';
  }
  return 0;
}