#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>
 
using namespace std;
 
const int K = 330;
 
int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  vector<int> log(K + 1);
  int q;
  cin >> q;
  vector<pair<int, int>> B(n);
  for (int i = 0; i < n; ++i)
    B[i] = make_pair(A[i], -1);
  for (int i = 0; i < q; ++i){
    int a;
    cin >> a;
    if (a == 1){
      int p, x;
      cin >> p >> x;
      B[p - 1] = make_pair(x, i % K);
    } else {
      int x;
      cin >> x;
      log[i % K] = x;
    }
    if (i % K == K - 1 || i == q - 1){
      vector<int> mx(K + 1);
      mx.back() = log.back();
      for (int j = K - 1; j >= 0; --j)
        mx[j] = max(mx[j + 1], log[j]);
 
      for (int j = 0; j < n; ++j){
        B[j] = make_pair(max(B[j].first, mx[B[j].second + 1]), -1);
      }
 
      for (int j = 0; j <= K; ++j)
        log[j] = 0;
    }
  }
  for (int i = 0; i < n; ++i)
    cout << B[i].first << " ";
  return 0;
}