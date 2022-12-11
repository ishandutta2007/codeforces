#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int N = 1000010;

int arr[N], dp[N], best[N];
int n, mx = 0, ans = 0;

int main() {

  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0;i < n;i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }
  sort(arr, arr+n, less<int>());
  for(int i = n-1;i >= 0;i--) {
    int val = arr[i];
    if(i+1 < n and arr[i] == arr[i+1]) {
      best[i] = best[i] + 1;
    }else {
      best[i] = 1;
      for(int j = val;j <= mx;j += val) {
        best[i] = max(best[i], dp[j] + 1);
      }
    }
    dp[val] = best[i];
    ans = max(ans, best[i]);
  }
  cout << ans << endl;
  return 0;
}