#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

int main(){
  int t;
  cin >> t;
  for (int query = 0; query < t; ++query){
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i){
      char c;
      cin >> c;
      d[i] = c - '0';
    }
    bool find = false;
    for (int num = 0; num < 10; ++num){
      vector<int> ans(n);
      bool ok = true;
      int first = n;
      for (int i = n - 1; i >= 0; --i){
        if (d[i] > num){
          first = i;
          ans[i] = 2;
        }
      }
      int last = -1;
      for (int i = 0; i < n; ++i){
        if (d[i] < num){
          last = i;
          ans[i] = 1;
        }
      }
      for (int i = 0; i < first; ++i){
        if (d[i] == num)
          ans[i] = 2;
      }
      for (int i = first; i <= last; ++i){
        if (d[i] == num)
          ok = false;
      }
      for (int i = last + 1; i < n; ++i){
        if (d[i] == num)
          ans[i] = 1;
      }
      int prev1 = 0;
      int prev2 = 0;
      for (int i = 0; i < n; ++i){
        if (ans[i] == 1){
          if (d[i] < prev1)
            ok = false;
          prev1 = d[i];
        } else {
          if (d[i] < prev2)
            ok = false;
          prev2 = d[i];
        }
      }
      if (ok){
        find = true;
        for (int x : ans)
          cout << x;
        cout << '\n';
        break;
      }
    }
    if (!find)
      cout << "-\n";
  }
  return 0;
}