#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    deque<int> dq(n);
    for (auto &i : dq) cin >> i;
    int a = 0, b = 0;
    a = dq[0];
    int last = dq[0];
    dq.pop_front();
    int turn = 1;
    while (!dq.empty()) {
      turn++;
      int cur = 0;
      if (turn % 2 == 0) {
        while (!dq.empty() && cur <= last) {
          b += dq.back();
          cur += dq.back();
          dq.pop_back();
        }
      } else {
        while (!dq.empty() && cur <= last) {
          a += dq.front();
          cur += dq.front();
          dq.pop_front();
        }
      }
      last = cur;
    }
    cout << turn << " " << a << " " << b << "\n";
  }  
}