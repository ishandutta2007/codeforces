#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const int N = 110;

int arr[N];
int n, m;

int main() {
  cin >> n >> m;
  for(int i = 0;i < n;i++) cin >> arr[i];
  sort(arr, arr+n, greater<int>());
  for(int i = 0, val = 0;i < n;i++) {
    val += arr[i];
    if(val >= m) {
      cout << (i+1) << endl;
      break;
    }
  }
  return 0;
}