#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;

  const auto And = [&](int i, int j) {
    cout << "AND " << i + 1 << " " << j + 1 << endl;
    int x;
    cin >> x;
    return x;
  };

  const auto Or = [&](int i, int j) {
    cout << "OR " << i + 1 << " " << j + 1 << endl;
    int x;
    cin >> x;
    return x;
  };

  const auto Xor = [&](int i, int j) {
    cout << "XOR " << i + 1 << " " << j + 1 << endl;
    int x;
    cin >> x;
    return x;
  };

  int axorb = Xor(0, 1);
  int axorc = Xor(0, 2);
  int bxorc = axorb ^ axorc;

  int aorb = Or(0, 1);
  int aorc = Or(0, 2);
  int borc = Or(1, 2);

  int aandb = aorb - axorb;
  int aandc = aorc - axorc;
  int bandc = borc - bxorc;
  
  int aplusb = aorb + aandb;
  int aplusc = aorc + aandc;
  int bplusc = borc + bandc;

  int sum = (aplusb + aplusc + bplusc) / 2;
  int a = sum - bplusc;
  int b = sum - aplusc;
  int c = sum - aplusb;

  vector<int> ans(n);
  ans[0] = a;
  ans[1] = b;
  ans[2] = c;
  for (int i = 3; i < n; i++) {
    ans[i] = Xor(i - 1, i) ^ ans[i - 1];
  }  

  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}