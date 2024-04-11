#include <bits/stdc++.h>

using namespace std;

char x[1010];
int dd[30];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> x;
  for (int i = 0; i < strlen(x); i++) {
    dd[x[i] - 'a'] ^= 1;
  }
  int cnt = 0;
  for (int i = 0; i < 30; i++) {
    cnt += dd[i];
  }
  if (cnt == 0) {
    cout << "First\n";
  } else {
    if (cnt & 1) {
      cout << "First\n";
    } else {
      cout << "Second\n";
    }
  }
  return 0;
}