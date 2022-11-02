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
    int b, w;
    cin >> w >> b;
    if (b >= w){
      if (b > 3 * w + 1){
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
      for (int i = 0; i < 2 * w; ++i)
        cout << 3 + i << " " << 3 << "\n";
      b -= w;
      for (int i = 0; i < w && b > 0; ++i){
        cout << 4 + 2 * i << " " << 2 << "\n";
        --b;
      }
      for (int i = 0; i < w && b > 0; ++i){
        cout << 4 + 2 * i << " " << 4 << "\n";
        --b;
      }
      if (b > 0)
        cout << 2 * w + 3 << " " << 3 << "\n";
    } else {
      if (w > 3 * b + 1){
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
      for (int i = 0; i < 2 * b; ++i)
        cout << 4 + i << " " << 3 << "\n";
      w -= b;
      for (int i = 0; i < b && w > 0; ++i){
        cout << 5 + 2 * i << " " << 2 << "\n";
        --w;
      }
      for (int i = 0; i < b && w > 0; ++i){
        cout << 5 + 2 * i << " " << 4 << "\n";
        --w;
      }
      if (w > 0)
        cout << 2 * b + 4 << " " << 3 << "\n";
    }
  }
  return 0;
}