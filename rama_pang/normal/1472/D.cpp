#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(begin(a), end(a));
  long long A = 0, B = 0;
  int turn = 0;
  while (!a.empty()) {
    if (turn == 0) {
      if (a.back() % 2 == 0) {
        A += a.back();
      }
    } else {
      if (a.back() % 2 == 1) {
        B += a.back();
      }
    }
    turn ^= 1;
    a.pop_back();
  }
  if (A > B) {
    cout << "Alice\n";
  } else if (A == B) {
    cout << "Tie\n";
  } else {
    cout << "Bob\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}