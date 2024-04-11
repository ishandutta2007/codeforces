#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int arr[N];
int n;

int main() {
  ios::sync_with_stdio(false);
  
  int sum = 0;
  cin >> n;
  for(int i = 0;i < n;i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  int x = sum / n;
  int y = sum % n;
  sort(arr, arr+n);
  int ans = 0;
  for(int i = 0;i < n;i++) {
    int val = x + (i >= n-y);
    ans += abs(val - arr[i]);
  }
  ans /= 2;
  cout << ans << endl;
  return 0;
}