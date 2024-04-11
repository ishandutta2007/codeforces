#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int T;
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    if (n % 2 == 0){
      int k = n / 2;
      vector<pair<int, int>> A(k);
      vector<pair<int, int>> B(k);
      for (int i = 0; i < k; ++i)
        cin >> A[i].first;
      for (int i = k - 1; i >= 0; --i)
        cin >> A[i].second;
      for (int i = 0; i < k; ++i)
        cin >> B[i].first;
      for (int i = k - 1; i >= 0; --i)
        cin >> B[i].second;
      for (int i = 0; i < k; ++i){
        if (A[i].first > A[i].second)
          swap(A[i].first, A[i].second);
        if (B[i].first > B[i].second)
          swap(B[i].first, B[i].second);
      }
      sort(A.begin(), A.end());
      sort(B.begin(), B.end());
      bool ok = true;
      for (int i = 0; i < k; ++i)
        ok = ok && A[i] == B[i];
      if (ok)
        cout << "Yes\n";
      else
        cout << "No\n";
    } else {
      int k = n / 2;
      vector<pair<int, int>> A(k);
      vector<pair<int, int>> B(k);
      for (int i = 0; i < k; ++i)
        cin >> A[i].first;
      int x;
      cin >> x;
      for (int i = k - 1; i >= 0; --i)
        cin >> A[i].second;
      for (int i = 0; i < k; ++i)
        cin >> B[i].first;
      int y;
      cin >> y;
      for (int i = k - 1; i >= 0; --i)
        cin >> B[i].second;
      for (int i = 0; i < k; ++i){
        if (A[i].first > A[i].second)
          swap(A[i].first, A[i].second);
        if (B[i].first > B[i].second)
          swap(B[i].first, B[i].second);
      }
      sort(A.begin(), A.end());
      sort(B.begin(), B.end());
      bool ok = x == y;
      for (int i = 0; i < k; ++i)
        ok = ok && A[i] == B[i];
      if (ok)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}