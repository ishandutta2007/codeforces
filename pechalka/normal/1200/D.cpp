#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> A(n, vector<int>(n));
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      char c;
      cin >> c;
      A[i][j] = (c == 'B');
    }
  }
  vector<vector<int>> cnt(n - k + 1, vector<int>(n - k + 1));
  if (true){
    vector<int> vertSum(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j){
        vertSum[j] += A[i][j];
      }
    vector<vector<int>> sumDown(n - k + 1, vector<int>(n));
    for (int j = 0; j < n; ++j){
      deque<int> el;
      int nowsum = 0;
      for (int i = 0; i < k; ++i){
        el.push_back(A[i][j]);
        nowsum += A[i][j];
      }
      sumDown[0][j] = nowsum;
      for (int i = k; i < n; ++i){
        nowsum -= el.front();
        el.pop_front();
        el.push_back(A[i][j]);
        nowsum += A[i][j];
        sumDown[i - k + 1][j] = nowsum;
      }
    }
    int zero = 0;
    for (int j = 0; j < n; ++j)
      zero += (vertSum[j] == 0);
    for (int i = 0; i < n - k + 1; ++i){
      int nowsum = zero;
      for (int j = 0; j < k; ++j)
        nowsum += (vertSum[j] != 0 && sumDown[i][j] == vertSum[j]);
      cnt[i][0] += nowsum;
      for (int j = k; j < n; ++j){
        nowsum -= (vertSum[j - k] != 0 && sumDown[i][j - k] == vertSum[j - k]);
        nowsum += (vertSum[j] != 0 && sumDown[i][j] == vertSum[j]);
        cnt[i][j - k + 1] += nowsum;
      }
    }
  }
  if (true){
    vector<int> horSum(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j){
        horSum[i] += A[i][j];
      }
    vector<vector<int>> sumRight(n, vector<int>(n - k + 1));
    for (int i = 0; i < n; ++i){
      deque<int> el;
      int nowsum = 0;
      for (int j = 0; j < k; ++j){
        el.push_back(A[i][j]);
        nowsum += A[i][j];
      }
      sumRight[i][0] = nowsum;
      for (int j = k; j < n; ++j){
        nowsum -= el.front();
        el.pop_front();
        el.push_back(A[i][j]);
        nowsum += A[i][j];
        sumRight[i][j - k + 1] = nowsum;
      }
    }
    int zero = 0;
    for (int i = 0; i < n; ++i)
      zero += (horSum[i] == 0);
    for (int j = 0; j < n - k + 1; ++j){
      int nowsum = zero;
      for (int i = 0; i < k; ++i)
        nowsum += (horSum[i] != 0 && sumRight[i][j] == horSum[i]);
      cnt[0][j] += nowsum;
      for (int i = k; i < n; ++i){
        nowsum -= (horSum[i - k] != 0 && sumRight[i - k][j] == horSum[i - k]);
        nowsum += (horSum[i] != 0 && sumRight[i][j] == horSum[i]);
        cnt[i - k + 1][j] += nowsum;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n - k + 1; ++i)
    for (int j = 0; j < n - k + 1; ++j)
      ans = max(ans, cnt[i][j]);
  cout << ans;
  return 0;
}