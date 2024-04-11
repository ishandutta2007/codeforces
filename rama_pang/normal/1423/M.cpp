#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> A(M + 1);
  for (int i = 1; i <= M; i++) {
    cout << "? " << 1 << " " << i << endl;
    int x;
    cin >> x;
    A[i] = x;
  }

  vector<int> B(N + 1);
  for (int i = 1; i <= N; i++) {
    cout << "? " << i << " " << 1 << endl;
    int x;
    cin >> x;
    B[i] = x;
  }

  int x = min_element(begin(B) + 1, end(B)) - begin(B);
  int y = min_element(begin(A) + 1, end(A)) - begin(A);

  cout << "? " << x << " " << y << endl;
  int ans;
  cin >> ans;
  cout << "! " << ans << endl;
  return 0;
}