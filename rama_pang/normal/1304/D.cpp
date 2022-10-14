#include <bits/stdc++.h>
using namespace std;

int N;
string S;

// find lexicographically minimum and maximum permutation

void solve() {
  cin >> N >> S;
  int mn = 0, mx = 0, cur = 0;
  vector<int> small(N), large(N);
  vector<int> bal(N + 2);
  // largest = find lexicographic minimum permutation
  for (int i = 0; i < N; i++) {
    small[i] = cur;
    if (i + 1 < N && S[i] == '>') {
      cur = mn - 1;
      mn = cur;
    } else if (i + 1 < N && S[i] == '<') {
      cur = mx + 1;
      mx = cur;
    }
  }
  for (int i = 0; i < N; i++) {
    small[i] -= mn;
    small[i]++;
  }

  // for (int i = 0; i < N; i++) {
  //   if (i > 0) {
  //     bal[i + 1] = bal[i];
  //   }
  //   if (i + 1 < N) {
  //     bal[i + 1] += (S[i] == '>' ? -1 : + 1);
  //   }
  // }
  // mn = *min_element(begin(bal), end(bal));
  // for (int i = 0; i <= N + 1; i++) {
  //   bal[i] -= mn;
  //   bal[i]++;
  //   // bal[i] = N - bal[i] + 1;
  // }
  // for (int i = N; i >= 0; i--) {
  //   bal[i] = min(bal[i], bal[i + 1]);
  // }
  int last = N;
  vector<int> add(N + 2, 0);
  cur = 0, mn = 0, mx = 0;
  for (int i = N - 1; i >= 0; i--) {
    large[i] = cur;
    if (i > 0) {
      if (S[i - 1] == '>') {
        cur = mx + 1;
        mx = cur;
        last = i;
      } else {
        add[i]++;
        add[last]--;
        mx++;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (i > 0) {
      add[i] += add[i - 1];
    }
    large[i] += add[i];
  }
  // for (int i = 0; i < N; i++) {
  //   cout << bal[i] << " ";
  // } cout << "\n";

  for (int i = 0; i < N; i++) {
    large[i] -= mn;
    large[i]++;
  }


  for (int i = 0; i < N; i++) {
    cout << large[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < N; i++) {
    cout << small[i] << " ";
  }
  cout << "\n";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}