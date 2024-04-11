#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  bool used[10];
  for (int i = 0; i < 10; ++i)
    used[i] = false;
  for (int i = 0; i < n; ++i){
    char c;
    cin >> c;
    if (c == 'L'){
      int i = 0;
      while (used[i])
        ++i;
      used[i] = true;
    } else if (c == 'R'){
      int i = 9;
      while (used[i])
        --i;
      used[i] = true;
    } else {
      used[c - '0'] = false;
    }
  }
  for (int i = 0; i < 10; ++i)
    cout << used[i];
  return 0;
}